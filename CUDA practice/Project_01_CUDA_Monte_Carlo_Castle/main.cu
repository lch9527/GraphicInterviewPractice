#include <cuda_runtime.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef NUMTRIALS
#define NUMTRIALS 1048576
#endif

#ifndef BLOCKSIZE
#define BLOCKSIZE 128
#endif

#ifndef GMIN
#define GMIN 10.0f
#define GMAX 20.0f
#define HMIN 20.0f
#define HMAX 30.0f
#define DMIN 10.0f
#define DMAX 20.0f
#define VMIN 20.0f
#define VMAX 30.0f
#define THMIN 70.0f
#define THMAX 80.0f
#endif

#define CUDA_CHECK(call) do { \
    cudaError_t err = (call); \
    if (err != cudaSuccess) { \
        fprintf(stderr, "CUDA error %s:%d: %s\n", __FILE__, __LINE__, cudaGetErrorString(err)); \
        exit(1); \
    } \
} while (0)

static float Ranf(float low, float high)
{
    float t = (float)rand() / (float)RAND_MAX;
    return low + t * (high - low);
}

__global__ void CastleKernel(const float* g, const float* h, const float* d,
                             const float* v, const float* thetaDeg,
                             int* hits, int n)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i >= n) {
        return;
    }

    const float gravity = -9.8f;
    const float tol = 5.0f;
    const float radians = thetaDeg[i] * 3.1415926535f / 180.0f;
    float vx = v[i] * cosf(radians);
    float vy = v[i] * sinf(radians);

    int hit = 0;
    // TODO: implement the same geometric tests as the original Monte Carlo project:
    // 1. Does the ball reach the cliff face?
    // 2. Is it high enough at the cliff face?
    // 3. Where does it intersect the upper deck height on the way down?
    // 4. Is the landing distance within tol of the castle distance?
    (void)gravity;
    (void)tol;
    (void)vx;
    (void)vy;
    (void)g;
    (void)h;
    (void)d;

    hits[i] = hit;
}

int main()
{
    const int floatBytes = NUMTRIALS * (int)sizeof(float);
    const int intBytes = NUMTRIALS * (int)sizeof(int);

    float *hG = (float*)malloc(floatBytes), *hH = (float*)malloc(floatBytes);
    float *hD = (float*)malloc(floatBytes), *hV = (float*)malloc(floatBytes);
    float *hTheta = (float*)malloc(floatBytes);
    int* hHits = (int*)malloc(intBytes);
    if (!hG || !hH || !hD || !hV || !hTheta || !hHits) {
        fprintf(stderr, "host allocation failed\n");
        return 1;
    }

    for (int i = 0; i < NUMTRIALS; i++) {
        hG[i] = Ranf(GMIN, GMAX);
        hH[i] = Ranf(HMIN, HMAX);
        hD[i] = Ranf(DMIN, DMAX);
        hV[i] = Ranf(VMIN, VMAX);
        hTheta[i] = Ranf(THMIN, THMAX);
    }

    float *dG, *dH, *dD, *dV, *dTheta;
    int* dHits;
    CUDA_CHECK(cudaMalloc(&dG, floatBytes));
    CUDA_CHECK(cudaMalloc(&dH, floatBytes));
    CUDA_CHECK(cudaMalloc(&dD, floatBytes));
    CUDA_CHECK(cudaMalloc(&dV, floatBytes));
    CUDA_CHECK(cudaMalloc(&dTheta, floatBytes));
    CUDA_CHECK(cudaMalloc(&dHits, intBytes));
    CUDA_CHECK(cudaMemcpy(dG, hG, floatBytes, cudaMemcpyHostToDevice));
    CUDA_CHECK(cudaMemcpy(dH, hH, floatBytes, cudaMemcpyHostToDevice));
    CUDA_CHECK(cudaMemcpy(dD, hD, floatBytes, cudaMemcpyHostToDevice));
    CUDA_CHECK(cudaMemcpy(dV, hV, floatBytes, cudaMemcpyHostToDevice));
    CUDA_CHECK(cudaMemcpy(dTheta, hTheta, floatBytes, cudaMemcpyHostToDevice));

    cudaEvent_t start, stop;
    CUDA_CHECK(cudaEventCreate(&start));
    CUDA_CHECK(cudaEventCreate(&stop));
    CUDA_CHECK(cudaEventRecord(start));
    CastleKernel<<<(NUMTRIALS + BLOCKSIZE - 1) / BLOCKSIZE, BLOCKSIZE>>>(
        dG, dH, dD, dV, dTheta, dHits, NUMTRIALS);
    CUDA_CHECK(cudaGetLastError());
    CUDA_CHECK(cudaEventRecord(stop));
    CUDA_CHECK(cudaEventSynchronize(stop));

    float ms = 0.0f;
    CUDA_CHECK(cudaEventElapsedTime(&ms, start, stop));
    CUDA_CHECK(cudaMemcpy(hHits, dHits, intBytes, cudaMemcpyDeviceToHost));

    int hits = 0;
    for (int i = 0; i < NUMTRIALS; i++) {
        hits += hHits[i];
    }

    printf("NUMTRIALS=%d BLOCKSIZE=%d probability=%.4f%% MegaTrialsPerSecond=%.2f\n",
           NUMTRIALS, BLOCKSIZE, 100.0 * (double)hits / (double)NUMTRIALS,
           (double)NUMTRIALS / ((double)ms / 1000.0) / 1000000.0);

    CUDA_CHECK(cudaFree(dG));
    CUDA_CHECK(cudaFree(dH));
    CUDA_CHECK(cudaFree(dD));
    CUDA_CHECK(cudaFree(dV));
    CUDA_CHECK(cudaFree(dTheta));
    CUDA_CHECK(cudaFree(dHits));
    free(hG); free(hH); free(hD); free(hV); free(hTheta); free(hHits);
    return 0;
}
