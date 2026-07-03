# CUDA Practice

This folder adapts the CS 475/575 Spring 2025 programming projects from Oregon State's Parallel Programming course into CUDA-focused practice projects.

Source course page: https://web.engr.oregonstate.edu/~mjb/cs575/

The original project list includes Projects #0 through #7 and a 575-only paper assignment. This practice set intentionally includes only the programming projects and omits the 575-only paper.

## Projects

| Folder | CUDA practice goal |
| --- | --- |
| `Project_00_CUDA_Array_Multiply` | Convert the simple OpenMP array multiply experiment into a CUDA kernel timing exercise. |
| `Project_01_CUDA_Monte_Carlo_Castle` | Convert the OpenMP Monte Carlo castle simulation into a CUDA Monte Carlo kernel. |
| `Project_02_CUDA_Grain_Deer_Simulation` | Convert the functional decomposition simulation into a month-by-month GPU state update exercise. |
| `Project_03_CUDA_KMeans_Cities` | Convert the OpenMP K-means city grouping challenge into CUDA assignment and reduction kernels. |
| `Project_04_CUDA_Array_Reduction` | Convert the SSE array multiply/reduction benchmark into CUDA memory bandwidth and reduction practice. |
| `Project_05_CUDA_Monte_Carlo_Castle` | CUDA version of the course's CUDA Monte Carlo project. |
| `Project_06_CUDA_Quadratic_Regression` | Convert the OpenCL quadratic regression project into CUDA partial-sum and reduction practice. |
| `Project_07_CUDA_Fourier_Analysis` | Convert the MPI Fourier analysis project into a CUDA period-scan kernel. |

## Build Notes

Each project is standalone:

```powershell
nvcc -O0 -lineinfo main.cu -o main.exe
.\main.exe
```

Most skeletons expose benchmark constants with `-D`, for example:

```powershell
nvcc -O0 -DNUMTRIALS=1048576 -DBLOCKSIZE=128 main.cu -o main.exe
```

The course page warns not to use aggressive optimization for benchmark assignments. These skeletons default examples to `-O0` for that reason.

## nvcc Command-Line Practice

Use these commands while working through each CUDA project in WSL. The `-arch=sm_89` flag targets the RTX 4060 laptop GPU and avoids relying on driver-side PTX JIT for this setup.

Check the CUDA tools:

```bash
nvidia-smi
nvcc --version
```

Build and run the current project:

```bash
nvcc -O0 -arch=sm_89 main.cu -o main
./main
```

Build with benchmark constants:

```bash
nvcc -O0 -arch=sm_89 -DSIZE=1048576 -DBLOCKSIZE=128 main.cu -o main
./main
```

Keep source line information for profiling or debugging:

```bash
nvcc -O0 -arch=sm_89 -lineinfo main.cu -o main
```

Generate intermediate files to see what `nvcc` is doing:

```bash
nvcc -O0 -arch=sm_89 --keep main.cu -o main
```

Compile only, then link separately:

```bash
nvcc -O0 -arch=sm_89 -c main.cu -o main.o
nvcc main.o -o main
```

Clean local build outputs:

```bash
rm -f main main.o *.ptx *.cubin *.fatbin *.ii *.i *.cudafe* *.module_id *.gpu *.cpp*
```

Suggested drill for each project:

1. Build once with plain `-O0 -arch=sm_89`.
2. Rebuild with two different `-D` values, such as `BLOCKSIZE=64` and `BLOCKSIZE=256`.
3. Add `-lineinfo` and confirm the program still runs.
4. Use `--keep` once, inspect the generated files, then clean them.


