# Project 04: CUDA Array Multiplication and Reduction

## Background

Original CS575 project: Vectorized Array Multiplication and Multiplication/Reduction using SSE.

The original assignment compares scalar C/C++ loops with SSE SIMD. This CUDA adaptation compares CPU loops with CUDA kernels for array multiply and multiply/reduce.

## Goal

Implement two CUDA paths: one kernel for `C[i] = A[i] * B[i]`, and one reduction kernel for `sum(A[i] * B[i])`. Vary array size and block size, then graph speedup relative to CPU serial code.

## Source Material

- Course page: https://web.engr.oregonstate.edu/~mjb/cs575/
- Original project page: http://cs.oregonstate.edu/~mjb/cs575/Projects/proj04.html
- Related PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/simd.vector.1pp.pdf
- Related video: https://media.oregonstate.edu/media/t/1_ihp84pou
- CUDA array multiplication PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/cudaArrayMult.1pp.pdf

## Tasks

1. Complete the elementwise multiply kernel.
2. Complete shared-memory block reduction.
3. Finish the second-stage CPU or GPU reduction.
4. Report speedup curves versus array size.

## Build

```powershell
nvcc -O0 -DSIZE=1048576 -DBLOCKSIZE=256 main.cu -o main.exe
.\main.exe
```
