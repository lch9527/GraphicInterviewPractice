# Project 06: CUDA Quadratic Regression

## Background

Original CS575 project: OpenCL Quadratic Regression.

The original assignment computes seven independent summation terms for a quadratic regression using OpenCL. This CUDA adaptation computes the same per-point terms in CUDA and leaves the first version's final reduction on the CPU.

## Goal

Read or generate `(x, y)` pairs, compute partial terms for `x^4`, `x^3`, `x^2`, `x`, `x^2*y`, `x*y`, and `y` on the GPU, reduce them, and solve for `Q`, `L`, and `C` in `y = Qx^2 + Lx + C`.

## Source Material

- Course page: https://web.engr.oregonstate.edu/~mjb/cs575/
- Original project page: http://cs.oregonstate.edu/~mjb/cs575/Projects/proj06.html
- Related PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/opencl.1pp.pdf
- Related video: https://media.oregonstate.edu/media/t/1_htlezpm8
- CUDA transition PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/transition_cuda_opencl.1pp.pdf

## Tasks

1. Replace generated sample data with `p6.data` if desired.
2. Complete `TermsKernel`.
3. Reduce all seven arrays.
4. Implement or call a 3x3 solver.
5. Graph performance versus `DATASIZE` and `BLOCKSIZE`.

## Build

```powershell
nvcc -O0 -DDATASIZE=1048576 -DBLOCKSIZE=256 main.cu -o main.exe
.\main.exe
```
