# Profiling And Debugging Cheat Sheet

Use this when they ask how you would investigate performance or correctness issues.

## Core Rule

Measure before optimizing.

Good interview sentence:

> I would not guess at the bottleneck. I would instrument the system first and isolate where time is actually going.

## Profiling Vs Debugging

- `profiling` finds where time, memory, or bandwidth is being spent
- `debugging` finds why behavior is wrong

Often you need both.

## Simple Investigation Flow

1. Reproduce the issue consistently.
2. Define the failure clearly.
3. Add timestamps or measurements around each stage.
4. Separate CPU time, GPU time, queue wait time, copy time, and network time.
5. Identify the biggest bottleneck or incorrect assumption.
6. Fix one thing at a time.
7. Re-test and check regressions.

Good interview sentence:

> My first goal is to turn the problem from a vague symptom into a measurable stage-by-stage breakdown.

## Questions To Ask Yourself

- Is this CPU-bound or GPU-bound?
- Is latency the issue, or only throughput?
- Is the problem a stall, a copy, a lock, a queue buildup, or a compute hotspot?
- Is average performance fine but frame pacing bad?
- Did a correctness bug create the performance issue?

## Common Bottleneck Types

### CPU-Bound

- too much work on CPU threads
- lock contention
- expensive per-frame logic

### GPU-Bound

- shaders or compute too heavy
- too much bandwidth or texture traffic
- bad synchronization

### Memory / Copy Bottleneck

- moving too much data
- poor data layout
- readback stalls

### Queue / Pipeline Bottleneck

- one stage slower than the rest
- work builds up
- latency rises over time

## Good Phrases For Interview Answers

> I would break the system into stages and measure each stage independently.

> I would check whether the problem is throughput, latency, or frame pacing, because the fix can be different.

> If a pipeline is interactive, average FPS alone is not enough. Tail latency and stalls matter.

## Validation After A Fix

After changing something, check:

- correctness
- latency
- frame pacing
- memory usage
- stability under load

## Safe Honest Answer

> My default debugging style is to make the problem reproducible, instrument the system, separate the pipeline into stages, and use data to decide what to optimize first.
