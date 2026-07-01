# Project 05: CUDA Monte Carlo Castle

## Background

Original CS575 project: CUDA Monte Carlo Simulation.

This project is already CUDA in the course. The skeleton here keeps the same concept: many independent projectile trials, CUDA timing, and benchmark sweeps over `NUMTRIALS` and `BLOCKSIZE`.

## Goal

Complete the CUDA kernel, store one hit flag per trial, sum the results on the CPU, and report the estimated probability plus MegaTrials/Second. Use the Project #5 ranges, not the Project #1 ranges.

## Source Material

- Course page: https://web.engr.oregonstate.edu/~mjb/cs575/
- Original project page: http://cs.oregonstate.edu/~mjb/cs575/Projects/proj05.html
- Related PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/cuda.1pp.pdf
- Related video: https://media.oregonstate.edu/media/t/1_5ctepen5
- CUDA array multiplication PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/cudaArrayMult.1pp.pdf

## Tasks

1. Fill random inputs on the CPU.
2. Complete the GPU hit test.
3. Use CUDA events for timing.
4. Sweep at least `BLOCKSIZE = 8, 32, 64, 128, 256`.
5. Explain why very small blocks underperform.

## Build

```powershell
nvcc -O0 -DNUMTRIALS=2097152 -DBLOCKSIZE=128 main.cu -o main.exe
.\main.exe
```
