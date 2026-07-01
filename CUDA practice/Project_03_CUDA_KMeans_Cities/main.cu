#include <cuda_runtime.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef NUMCITIES
#define NUMCITIES 331
#endif

#ifndef NUMCAPITALS
#define NUMCAPITALS 10
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

__global__ void AssignKernel(const float* cityLon, const float* cityLat,
                             const float* capLon, const float* capLat,
                             int* assignment, int nCities, int nCapitals)
{
    int city = blockIdx.x * blockDim.x + threadIdx.x;
    if (city >= nCities) {
        return;
    }

    float bestDist = FLT_MAX;
    int best = 0;
    for (int k = 0; k < nCapitals; k++) {
        float dx = cityLon[city] - capLon[k];
        float dy = cityLat[city] - capLat[k];
        float dist = dx * dx + dy * dy;
        // TODO: update best and bestDist.
        (void)dist;
    }
    assignment[city] = best;
}

static void RecomputeCentroids(const float* lon, const float* lat, const int* assign,
                               float* capLon, float* capLat)
{
    float sumLon[NUMCAPITALS] = {};
    float sumLat[NUMCAPITALS] = {};
    int count[NUMCAPITALS] = {};

    for (int i = 0; i < NUMCITIES; i++) {
        int k = assign[i];
        sumLon[k] += lon[i];
        sumLat[k] += lat[i];
        count[k]++;
    }

    for (int k = 0; k < NUMCAPITALS; k++) {
        if (count[k] > 0) {
            capLon[k] = sumLon[k] / (float)count[k];
            capLat[k] = sumLat[k] / (float)count[k];
        }
    }
}

int main()
{
    float hLon[NUMCITIES], hLat[NUMCITIES];
    float hCapLon[NUMCAPITALS], hCapLat[NUMCAPITALS];
    int hAssign[NUMCITIES] = {};

    for (int i = 0; i < NUMCITIES; i++) {
        hLon[i] = -125.0f + (float)(i % 61);
        hLat[i] = 25.0f + (float)((i * 7) % 25);
    }
    for (int k = 0; k < NUMCAPITALS; k++) {
        int index = (k * NUMCITIES) / NUMCAPITALS;
        hCapLon[k] = hLon[index];
        hCapLat[k] = hLat[index];
    }

    float *dLon, *dLat, *dCapLon, *dCapLat;
    int* dAssign;
    CUDA_CHECK(cudaMalloc(&dLon, NUMCITIES * sizeof(float)));
    CUDA_CHECK(cudaMalloc(&dLat, NUMCITIES * sizeof(float)));
    CUDA_CHECK(cudaMalloc(&dCapLon, NUMCAPITALS * sizeof(float)));
    CUDA_CHECK(cudaMalloc(&dCapLat, NUMCAPITALS * sizeof(float)));
    CUDA_CHECK(cudaMalloc(&dAssign, NUMCITIES * sizeof(int)));
    CUDA_CHECK(cudaMemcpy(dLon, hLon, NUMCITIES * sizeof(float), cudaMemcpyHostToDevice));
    CUDA_CHECK(cudaMemcpy(dLat, hLat, NUMCITIES * sizeof(float), cudaMemcpyHostToDevice));

    for (int iter = 0; iter < 100; iter++) {
        CUDA_CHECK(cudaMemcpy(dCapLon, hCapLon, NUMCAPITALS * sizeof(float), cudaMemcpyHostToDevice));
        CUDA_CHECK(cudaMemcpy(dCapLat, hCapLat, NUMCAPITALS * sizeof(float), cudaMemcpyHostToDevice));
        AssignKernel<<<(NUMCITIES + BLOCKSIZE - 1) / BLOCKSIZE, BLOCKSIZE>>>(
            dLon, dLat, dCapLon, dCapLat, dAssign, NUMCITIES, NUMCAPITALS);
        CUDA_CHECK(cudaGetLastError());
        CUDA_CHECK(cudaMemcpy(hAssign, dAssign, NUMCITIES * sizeof(int), cudaMemcpyDeviceToHost));
        RecomputeCentroids(hLon, hLat, hAssign, hCapLon, hCapLat);
    }

    printf("NUMCITIES=%d NUMCAPITALS=%d firstCapital=(%.2f, %.2f)\n",
           NUMCITIES, NUMCAPITALS, hCapLon[0], hCapLat[0]);

    CUDA_CHECK(cudaFree(dLon));
    CUDA_CHECK(cudaFree(dLat));
    CUDA_CHECK(cudaFree(dCapLon));
    CUDA_CHECK(cudaFree(dCapLat));
    CUDA_CHECK(cudaFree(dAssign));
    return 0;
}
