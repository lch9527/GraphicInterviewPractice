# Project 00: CUDA Array Multiply

## Background

Original CS575 project: Simple OpenMP Experiment.

The original assignment benchmarks pairwise multiplication of two large float arrays using one CPU thread versus four OpenMP threads. This CUDA adaptation moves the same data-parallel operation to the GPU and compares CPU serial timing with CUDA kernel timing.

## Goal

Implement and benchmark `C[i] = A[i] * B[i]` on the GPU. Vary array size and block size, report peak MegaMultiplies/Second, and compare GPU performance with the CPU baseline.

## Source Material

- Course page: https://web.engr.oregonstate.edu/~mjb/cs575/
- Original project page: http://cs.oregonstate.edu/~mjb/cs575/Projects/proj00.html
- Related PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/openmp-simple.1pp.pdf
- Related video: https://media.oregonstate.edu/media/t/1_fyj7ues6
- CUDA background PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/cuda.1pp.pdf

## Tasks

1. Fill in the CUDA kernel bounds check and multiply.
2. Allocate and copy host/device arrays.
3. Time CPU and GPU runs.
4. Sweep `SIZE` and `BLOCKSIZE`.
5. Explain where overhead dominates and where throughput stabilizes.

## Build

```powershell
nvcc -O0 -DSIZE=1048576 -DBLOCKSIZE=128 main.cu -o main.exe
.\main.exe
```
