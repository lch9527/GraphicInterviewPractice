# Project 02: CUDA Grain and Deer Simulation

## Background

Original CS575 project: Functional Decomposition.

The original assignment uses OpenMP sections as independent simulation agents for grain, deer, watcher, and a custom phenomenon. CUDA is not a natural fit for a four-agent control-flow simulation, so this adaptation changes the emphasis: each month is still advanced in order on the CPU, but the GPU evaluates many candidate environments or scenarios in parallel.

## Goal

Simulate many independent grain/deer worlds on the GPU. Each CUDA thread owns one scenario and advances it month by month. Compare how different custom agents or initial states affect final grain height and deer population.

## Source Material

- Course page: https://web.engr.oregonstate.edu/~mjb/cs575/
- Original project page: http://cs.oregonstate.edu/~mjb/cs575/Projects/proj02.html
- Related PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/functional_decomposition.1pp.pdf
- Related video: https://media.oregonstate.edu/media/t/1_w8znkowm
- CUDA background PDF: http://cs.oregonstate.edu/~mjb/cs575/Handouts/cuda.1pp.pdf

## Tasks

1. Implement the grain growth and deer carrying-capacity update.
2. Add one custom phenomenon per scenario, such as disease, irrigation, or pests.
3. Write final state arrays back to the CPU.
4. Graph final outcomes across scenario parameters.

## Build

```powershell
nvcc -O0 -DSCENARIOS=65536 -DBLOCKSIZE=128 main.cu -o main.exe
.\main.exe
```
