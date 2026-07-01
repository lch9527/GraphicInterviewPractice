# Project 07: CUDA Fourier Analysis

## Background

Original CS575 project: Fourier Analysis using MPI.

The original assignment divides signal work across MPI processes. This CUDA adaptation assigns periods to GPU threads or thread blocks and computes Fourier-like sums for each candidate period.

## Goal

Load or generate a signal, compute one sum per period on the GPU, copy sums back to the CPU, and identify the two strongest periods. Benchmark performance versus signal size, maximum period, and block size.

## Source Material

- Course page: https://web.engr.oregonstate.edu/~mjb/cs575/
- Original project page: http://cs.oregonstate.edu/~mjb/cs575/Projects/proj07.html
- Related PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/mpi.1pp.pdf
- Related video: https://media.oregonstate.edu/media/t/1_f4oevct9
- CUDA background PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/cuda.1pp.pdf

## Tasks

1. Replace generated signal data with `bigsignal.txt` or `bigsignal.bin` if desired.
2. Complete the period-sum kernel.
3. Find the top two periods on the CPU.
4. Graph sums versus period and performance versus configuration.

## Build

```powershell
nvcc -O0 -DNUMELEMENTS=1048576 -DMAXPERIODS=1024 -DBLOCKSIZE=128 main.cu -o main.exe
.\main.exe
```
