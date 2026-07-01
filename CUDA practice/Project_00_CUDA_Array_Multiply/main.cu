#include <cuda_runtime.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef SIZE
#define SIZE 1048576
#endif

#ifndef BLOCKSIZE
#define BLOCKSIZE 128
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
    // TODO: guard i and compute c[i].
}

static double ElapsedMs(cudaEvent_t start, cudaEvent_t stop)
{
    float ms = 0.0f;
    CUDA_CHECK(cudaEventElapsedTime(&ms, start, stop));
    return (double)ms;
}

int main()
{
    const int bytes = SIZE * (int)sizeof(float);
    float* hA = (float*)malloc(bytes);
    float* hB = (float*)malloc(bytes);
    float* hC = (float*)malloc(bytes);
    if (!hA || !hB || !hC) {
        fprintf(stderr, "host allocation failed\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        hA[i] = 1.0f + (float)(i % 17);
        hB[i] = 2.0f + (float)(i % 11);
        hC[i] = 0.0f;
    }

    float *dA = nullptr, *dB = nullptr, *dC = nullptr;
    CUDA_CHECK(cudaMalloc(&dA, bytes));
    CUDA_CHECK(cudaMalloc(&dB, bytes));
    CUDA_CHECK(cudaMalloc(&dC, bytes));
    CUDA_CHECK(cudaMemcpy(dA, hA, bytes, cudaMemcpyHostToDevice));
    CUDA_CHECK(cudaMemcpy(dB, hB, bytes, cudaMemcpyHostToDevice));

    dim3 block(BLOCKSIZE);
    dim3 grid((SIZE + BLOCKSIZE - 1) / BLOCKSIZE);

    cudaEvent_t start, stop;
    CUDA_CHECK(cudaEventCreate(&start));
    CUDA_CHECK(cudaEventCreate(&stop));
    CUDA_CHECK(cudaEventRecord(start));
    MultiplyKernel<<<grid, block>>>(dA, dB, dC, SIZE);
    CUDA_CHECK(cudaGetLastError());
    CUDA_CHECK(cudaEventRecord(stop));
    CUDA_CHECK(cudaEventSynchronize(stop));

    CUDA_CHECK(cudaMemcpy(hC, dC, bytes, cudaMemcpyDeviceToHost));
    double ms = ElapsedMs(start, stop);
    double megaMults = (double)SIZE / (ms / 1000.0) / 1000000.0;

    printf("SIZE=%d BLOCKSIZE=%d GPU_MegaMultsPerSecond=%.2f sample=%g\n",
           SIZE, BLOCKSIZE, megaMults, hC[SIZE / 2]);

    CUDA_CHECK(cudaEventDestroy(start));
    CUDA_CHECK(cudaEventDestroy(stop));
    CUDA_CHECK(cudaFree(dA));
    CUDA_CHECK(cudaFree(dB));
    CUDA_CHECK(cudaFree(dC));
    free(hA);
    free(hB);
    free(hC);
    return 0;
}
