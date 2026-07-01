#include <cuda_runtime.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef SCENARIOS
#define SCENARIOS 65536
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

__device__ float Sqr(float x) { return x * x; }

__global__ void SimulateKernel(float* finalHeight, int* finalDeer, float* finalAgent, int scenarios)
{
    int id = blockIdx.x * blockDim.x + threadIdx.x;
    if (id >= scenarios) {
        return;
    }

    int deer = 2 + (id % 5);
    float height = 5.0f + (float)(id % 13) * 0.25f;
    float agent = 1.0f + (float)(id % 17) * 0.02f;

    for (int monthIndex = 0; monthIndex < 72; monthIndex++) {
        int month = monthIndex % 12;
        float angle = (30.0f * (float)month + 15.0f) * 3.1415926535f / 180.0f;
        float temp = 60.0f - 20.0f * cosf(angle);
        float precip = 7.0f + 6.0f * sinf(angle);
        if (precip < 0.0f) {
            precip = 0.0f;
        }

        float tempFactor = expf(-Sqr((temp - 40.0f) / 10.0f));
        float precipFactor = expf(-Sqr((precip - 10.0f) / 10.0f));

        // TODO: define how agent changes growth or deer survival.
        float nextHeight = height + agent * tempFactor * precipFactor * 12.0f - (float)deer;
        if (nextHeight < 0.0f) {
            nextHeight = 0.0f;
        }

        int carryingCapacity = (int)height;
        int nextDeer = deer;
        if (nextDeer < carryingCapacity) {
            nextDeer++;
        } else if (nextDeer > carryingCapacity) {
            nextDeer--;
        }
        if (nextDeer < 0) {
            nextDeer = 0;
        }

        height = nextHeight;
        deer = nextDeer;
    }

    finalHeight[id] = height;
    finalDeer[id] = deer;
    finalAgent[id] = agent;
}

int main()
{
    float *dHeight, *dAgent;
    int* dDeer;
    CUDA_CHECK(cudaMalloc(&dHeight, SCENARIOS * sizeof(float)));
    CUDA_CHECK(cudaMalloc(&dAgent, SCENARIOS * sizeof(float)));
    CUDA_CHECK(cudaMalloc(&dDeer, SCENARIOS * sizeof(int)));

    SimulateKernel<<<(SCENARIOS + BLOCKSIZE - 1) / BLOCKSIZE, BLOCKSIZE>>>(
        dHeight, dDeer, dAgent, SCENARIOS);
    CUDA_CHECK(cudaGetLastError());
    CUDA_CHECK(cudaDeviceSynchronize());

    float sampleHeight = 0.0f, sampleAgent = 0.0f;
    int sampleDeer = 0;
    CUDA_CHECK(cudaMemcpy(&sampleHeight, dHeight, sizeof(float), cudaMemcpyDeviceToHost));
    CUDA_CHECK(cudaMemcpy(&sampleDeer, dDeer, sizeof(int), cudaMemcpyDeviceToHost));
    CUDA_CHECK(cudaMemcpy(&sampleAgent, dAgent, sizeof(float), cudaMemcpyDeviceToHost));

    printf("SCENARIOS=%d sampleHeight=%.3f sampleDeer=%d sampleAgent=%.3f\n",
           SCENARIOS, sampleHeight, sampleDeer, sampleAgent);

    CUDA_CHECK(cudaFree(dHeight));
    CUDA_CHECK(cudaFree(dAgent));
    CUDA_CHECK(cudaFree(dDeer));
    return 0;
}
