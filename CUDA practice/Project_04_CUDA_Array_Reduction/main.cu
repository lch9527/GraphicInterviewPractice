#include <cuda_runtime.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef SIZE
#define SIZE 1048576
#endif

#ifndef BLOCKSIZE
#define BLOCKSIZE 256
#endif

#define CUDA_CHECK(call) do { \
    cudaError_t err = (call); \
    if (err != cudaSuccess) { \
        fprintf(stderr, "CUDA error %s:%d: %s\n", __FILE__, __LINE__, cudaGetErrorString(err)); \
        exit(1); \
    } \
} while (0)

__global__ void MultiplyKernel(const float* a, const float* b, float* c, int n)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    // TODO: compute c[i] when in range.
}

__global__ void MultiplyReduceKernel(const float* a, const float* b, float* blockSums, int n)
{
    __shared__ float shared[BLOCKSIZE];
    int tid = threadIdx.x;
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    float value = 0.0f;
    if (i < n) {
        value = a[i] * b[i];
    }
    shared[tid] = value;
    __syncthreads();

    for (int stride = blockDim.x / 2; stride > 0; stride >>= 1) {
        if (tid < stride) {
            // TODO: add the upper half into the lower half.
        }
        __syncthreads();
    }

    if (tid == 0) {
        blockSums[blockIdx.x] = shared[0];
    }
}

int main()
{
    int grid = (SIZE + BLOCKSIZE - 1) / BLOCKSIZE;
    int bytes = SIZE * (int)sizeof(float);
    float* hA = (float*)malloc(bytes);
    float* hB = (float*)malloc(bytes);
    float* hC = (float*)malloc(bytes);
    float* hBlockSums = (float*)malloc(grid * sizeof(float));

    for (int i = 0; i < SIZE; i++) {
        hA[i] = 1.0f;
        hB[i] = 2.0f;
    }

    float *dA, *dB, *dC, *dBlockSums;
    CUDA_CHECK(cudaMalloc(&dA, bytes));
    CUDA_CHECK(cudaMalloc(&dB, bytes));
    CUDA_CHECK(cudaMalloc(&dC, bytes));
    CUDA_CHECK(cudaMalloc(&dBlockSums, grid * sizeof(float)));
    CUDA_CHECK(cudaMemcpy(dA, hA, bytes, cudaMemcpyHostToDevice));
    CUDA_CHECK(cudaMemcpy(dB, hB, bytes, cudaMemcpyHostToDevice));

    MultiplyKernel<<<grid, BLOCKSIZE>>>(dA, dB, dC, SIZE);
    CUDA_CHECK(cudaGetLastError());
    MultiplyReduceKernel<<<grid, BLOCKSIZE>>>(dA, dB, dBlockSums, SIZE);
    CUDA_CHECK(cudaGetLastError());
    CUDA_CHECK(cudaDeviceSynchronize());
    CUDA_CHECK(cudaMemcpy(hC, dC, bytes, cudaMemcpyDeviceToHost));
    CUDA_CHECK(cudaMemcpy(hBlockSums, dBlockSums, grid * sizeof(float), cudaMemcpyDeviceToHost));

    double sum = 0.0;
    for (int i = 0; i < grid; i++) {
        sum += hBlockSums[i];
    }
    printf("SIZE=%d BLOCKSIZE=%d sampleProduct=%g partialReductionSum=%g\n",
           SIZE, BLOCKSIZE, hC[0], sum);

    CUDA_CHECK(cudaFree(dA));
    CUDA_CHECK(cudaFree(dB));
    CUDA_CHECK(cudaFree(dC));
    CUDA_CHECK(cudaFree(dBlockSums));
    free(hA); free(hB); free(hC); free(hBlockSums);
    return 0;
}
