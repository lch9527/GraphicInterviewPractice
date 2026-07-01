#include <cuda_runtime.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef DATASIZE
#define DATASIZE 1048576
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

__global__ void TermsKernel(const float* x, const float* y,
                            float* x4, float* x3, float* x2, float* x1,
                            float* x2y, float* xy, float* y1, int n)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i >= n) {
        return;
    }

    float xi = x[i];
    float yi = y[i];
    // TODO: compute all seven regression summation terms.
    x4[i] = 0.0f;
    x3[i] = 0.0f;
    x2[i] = 0.0f;
    x1[i] = xi;
    x2y[i] = 0.0f;
    xy[i] = 0.0f;
    y1[i] = yi;
}

static double SumHost(const float* values, int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += values[i];
    }
    return sum;
}

int main()
{
    int bytes = DATASIZE * (int)sizeof(float);
    float* hX = (float*)malloc(bytes);
    float* hY = (float*)malloc(bytes);
    float* hTmp = (float*)malloc(bytes);
    for (int i = 0; i < DATASIZE; i++) {
        hX[i] = -1.0f + 2.0f * (float)i / (float)(DATASIZE - 1);
        hY[i] = 2.0f * hX[i] * hX[i] + 3.0f * hX[i] + 5.0f;
    }

    float *dX, *dY, *dX4, *dX3, *dX2, *dX1, *dX2Y, *dXY, *dY1;
    CUDA_CHECK(cudaMalloc(&dX, bytes));
    CUDA_CHECK(cudaMalloc(&dY, bytes));
    CUDA_CHECK(cudaMalloc(&dX4, bytes));
    CUDA_CHECK(cudaMalloc(&dX3, bytes));
    CUDA_CHECK(cudaMalloc(&dX2, bytes));
    CUDA_CHECK(cudaMalloc(&dX1, bytes));
    CUDA_CHECK(cudaMalloc(&dX2Y, bytes));
    CUDA_CHECK(cudaMalloc(&dXY, bytes));
    CUDA_CHECK(cudaMalloc(&dY1, bytes));
    CUDA_CHECK(cudaMemcpy(dX, hX, bytes, cudaMemcpyHostToDevice));
    CUDA_CHECK(cudaMemcpy(dY, hY, bytes, cudaMemcpyHostToDevice));

    TermsKernel<<<(DATASIZE + BLOCKSIZE - 1) / BLOCKSIZE, BLOCKSIZE>>>(
        dX, dY, dX4, dX3, dX2, dX1, dX2Y, dXY, dY1, DATASIZE);
    CUDA_CHECK(cudaGetLastError());
    CUDA_CHECK(cudaDeviceSynchronize());

    CUDA_CHECK(cudaMemcpy(hTmp, dY1, bytes, cudaMemcpyDeviceToHost));
    double sumY = SumHost(hTmp, DATASIZE);
    printf("DATASIZE=%d BLOCKSIZE=%d sumY=%g TODO_solve_Q_L_C\n",
           DATASIZE, BLOCKSIZE, sumY);

    CUDA_CHECK(cudaFree(dX)); CUDA_CHECK(cudaFree(dY));
    CUDA_CHECK(cudaFree(dX4)); CUDA_CHECK(cudaFree(dX3));
    CUDA_CHECK(cudaFree(dX2)); CUDA_CHECK(cudaFree(dX1));
    CUDA_CHECK(cudaFree(dX2Y)); CUDA_CHECK(cudaFree(dXY));
    CUDA_CHECK(cudaFree(dY1));
    free(hX); free(hY); free(hTmp);
    return 0;
}
