# Project 01: CUDA Monte Carlo Castle

## Background

Original CS575 project: OpenMP Monte Carlo Simulation.

The original assignment estimates the probability that a cannonball hits a castle using many independent random trials. This CUDA adaptation maps each Monte Carlo trial to one GPU thread.

## Goal

Generate trial inputs on the CPU, copy them to the GPU, classify hits in a CUDA kernel, copy hit flags back, and compute the hit probability and MegaTrials/Second. Sweep `NUMTRIALS` and `BLOCKSIZE`.

## Source Material

- Course page: https://web.engr.oregonstate.edu/~mjb/cs575/
- Original project page: http://cs.oregonstate.edu/~mjb/cs575/Projects/proj01.html
- Related PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/project.notes.1pp.pdf
- Related video: https://media.oregonstate.edu/media/t/1_f38ka1vy
- CUDA background PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/cuda.1pp.pdf

## Tasks

1. Complete the projectile equations inside `CastleKernel`.
2. Store `1` for a hit and `0` for a miss.
3. Reduce hit flags on the CPU first, then optionally add a GPU reduction.
4. Graph performance versus trial count and block size.

## Build

```powershell
nvcc -O0 -DNUMTRIALS=1048576 -DBLOCKSIZE=128 main.cu -o main.exe
.\main.exe
```
