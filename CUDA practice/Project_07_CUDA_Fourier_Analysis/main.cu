#include <cuda_runtime.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef NUMELEMENTS
#define NUMELEMENTS 1048576
#endif

#ifndef MAXPERIODS
#define MAXPERIODS 1024
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

__global__ void FourierKernel(const float* signal, float* sums, int n, int maxPeriods)
{
    int p = blockIdx.x * blockDim.x + threadIdx.x;
    if (p <= 0 || p >= maxPeriods) {
        return;
    }

    float omega = 6.283185307f / (float)p;
    float sum = 0.0f;
    for (int t = 0; t < n; t++) {
        // TODO: accumulate signal[t] * sin(omega * t).
        (void)omega;
    }
    sums[p] = sum;
}

int main()
{
    float* hSignal = (float*)malloc(NUMELEMENTS * sizeof(float));
    float* hSums = (float*)malloc(MAXPERIODS * sizeof(float));
    for (int i = 0; i < NUMELEMENTS; i++) {
        hSignal[i] = sinf(6.283185307f * (float)i / 97.0f)
                   + 0.5f * sinf(6.283185307f * (float)i / 233.0f);
    }

    float *dSignal, *dSums;
    CUDA_CHECK(cudaMalloc(&dSignal, NUMELEMENTS * sizeof(float)));
    CUDA_CHECK(cudaMalloc(&dSums, MAXPERIODS * sizeof(float)));
    CUDA_CHECK(cudaMemcpy(dSignal, hSignal, NUMELEMENTS * sizeof(float), cudaMemcpyHostToDevice));
    CUDA_CHECK(cudaMemset(dSums, 0, MAXPERIODS * sizeof(float)));

    FourierKernel<<<(MAXPERIODS + BLOCKSIZE - 1) / BLOCKSIZE, BLOCKSIZE>>>(
        dSignal, dSums, NUMELEMENTS, MAXPERIODS);
    CUDA_CHECK(cudaGetLastError());
    CUDA_CHECK(cudaDeviceSynchronize());
    CUDA_CHECK(cudaMemcpy(hSums, dSums, MAXPERIODS * sizeof(float), cudaMemcpyDeviceToHost));

    int bestA = 1, bestB = 2;
    for (int p = 1; p < MAXPERIODS; p++) {
        float mag = fabsf(hSums[p]);
        if (mag > fabsf(hSums[bestA])) {
            bestB = bestA;
            bestA = p;
        } else if (p != bestA && mag > fabsf(hSums[bestB])) {
            bestB = p;
        }
    }

    printf("NUMELEMENTS=%d MAXPERIODS=%d bestPeriods=%d,%d\n",
           NUMELEMENTS, MAXPERIODS, bestA, bestB);

    CUDA_CHECK(cudaFree(dSignal));
    CUDA_CHECK(cudaFree(dSums));
    free(hSignal);
    free(hSums);
    return 0;
}
