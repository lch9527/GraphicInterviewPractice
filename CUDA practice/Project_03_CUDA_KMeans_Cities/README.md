# Project 03: CUDA K-Means Cities

## Background

Original CS575 project: K-means parallel programming challenge.

The original assignment assigns U.S. cities to the nearest capital candidate and recomputes centroids repeatedly. This CUDA adaptation puts the nearest-capital assignment on the GPU and leaves the first centroid reduction on the CPU. An advanced version can move the centroid reduction to CUDA atomics or block reductions.

## Goal

Implement CUDA kernels for K-means assignment, then benchmark performance as `NUMCITIES`, `NUMCAPITALS`, and `BLOCKSIZE` vary.

## Source Material

- Course page: https://web.engr.oregonstate.edu/~mjb/cs575/
- Original project page: http://cs.oregonstate.edu/~mjb/cs575/Projects/proj03.html
- Related PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/data_decomposition.1pp.pdf
- Related video: https://media.oregonstate.edu/media/t/1_e8rj3emk
- CUDA background PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/cuda.1pp.pdf

## Tasks

1. Replace the placeholder sample data with the original city data or your own dataset.
2. Complete nearest-capital assignment in `AssignKernel`.
3. Compute new centroids on the CPU, then optionally on the GPU.
4. Report convergence behavior and throughput.

## Build

```powershell
nvcc -O0 -DNUMCITIES=331 -DNUMCAPITALS=10 -DBLOCKSIZE=128 main.cu -o main.exe
.\main.exe
```
