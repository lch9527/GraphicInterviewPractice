# Hardware Acceleration And CPU/GPU Sync Cheat Sheet

Use this as a practical review sheet for GPU/system questions.

## What Hardware Acceleration Means

Hardware acceleration means using specialized hardware instead of doing all work on the CPU.

In video and graphics, this often means:

- GPU compute work
- dedicated video encode/decode blocks
- specialized copy or processing hardware

Good interview sentence:

> Hardware acceleration offloads expensive work from the CPU to specialized hardware, but it also introduces integration and synchronization complexity.

## Why It Matters For This Role

This role mentions:

- GPU and graphics programming
- HLSL, Vulkan, CUDA
- codec pipeline optimization
- cloud gaming

That means they likely care about:

- how frames move through the system
- where compute runs
- how CPU and GPU coordinate
- where latency or stalls happen

## Simple Mental Model

Think of the CPU as the planner and the GPU as the worker.

- CPU prepares commands and data
- GPU executes work asynchronously
- performance problems happen when one side waits on the other too often

Good interview sentence:

> A common systems question is whether the CPU is waiting on the GPU, the GPU is starved by the CPU, or both are blocked by synchronization or memory movement.

## CPU/GPU Synchronization

Synchronization is the coordination needed so work happens in the correct order.

Examples:

- CPU must not read data before GPU finishes writing it
- GPU must not read a resource before a prior stage finishes updating it
- one queue may need to wait for another queue

Good interview sentence:

> Synchronization is necessary for correctness, but too much synchronization can destroy parallelism and increase latency.

## Common Problems

### GPU Readback Stall

This happens when the CPU needs data from the GPU and has to wait.

Why it hurts:

- breaks CPU/GPU overlap
- increases latency
- can stall the frame pipeline

### Too Many Copies

Moving frames or buffers around too much can waste time and bandwidth.

Why it hurts:

- memory bandwidth becomes the bottleneck
- extra copies add latency

### Over-Synchronization

Using too many waits, barriers, or forced completion points.

Why it hurts:

- reduces concurrency
- can make average performance look okay while frame pacing becomes bad

## What Interviewers Want To Hear

They want to hear that you:

- understand correctness vs performance tradeoffs
- know sync is necessary but expensive
- think about copies, stalls, and queueing
- measure before changing things

## Good Practical Phrases

> I would try to keep CPU and GPU work overlapped as much as possible.

> I would look for unnecessary waits, readbacks, or copies that serialize the pipeline.

> Even if average throughput looks fine, poor synchronization can still create latency spikes and bad frame pacing.

## Hardware Acceleration Tradeoff Summary

Benefits:

- lower CPU usage
- higher throughput
- better real-time feasibility

Costs:

- API complexity
- platform-specific behavior
- synchronization overhead
- debugging complexity

## Safe Honest Answer

> My strongest experience is in systems and performance reasoning rather than a production media stack, so I would approach hardware acceleration as a pipeline problem: where the work runs, how data moves, where the synchronization points are, and which waits or copies are hurting latency.
