# Technical Study Sheet

Use this as the focused technical review for both the HM interview and the later panel.

## Role Signals From The JD

The role is not only "codec math." It asks for:

- C/C++ systems programming
- Multithreading and concurrency
- GPU / graphics programming: HLSL, Vulkan, CUDA
- Debugging and profiling complex systems
- Video codec components for PlayStation SDKs and cloud gaming
- System-level performance analysis across the codec pipeline
- Collaboration with platform, hardware, and system software teams

## Codec Pipeline Mental Model

A cloud gaming video path can be explained as:

1. Game renders a frame.
2. Frame is copied or shared into a video pipeline.
3. Color conversion/scaling occurs, often RGB to YUV.
4. Encoder compresses the frame.
5. Bitstream is packetized and sent over the network.
6. Client receives, buffers, decodes, and renders.
7. Input feedback loop affects perceived latency.

Key idea:

> In cloud gaming, codec quality matters, but latency and frame pacing matter just as much.

## Codec Concepts To Know

- I-frame: intra-coded frame, no dependency on other frames, larger but useful for random access and recovery.
- P-frame: predicted from previous reference frames, smaller than I-frame.
- B-frame: predicted from past and future frames, efficient but can add latency/reordering.
- GOP: group of pictures; shorter GOP improves recovery but increases bitrate.
- Motion estimation: searches for similar blocks across frames.
- Transform and quantization: convert residual data and reduce precision.
- Entropy coding: compresses symbols statistically.
- Rate control: chooses bitrate/quality tradeoff under bandwidth constraints.
- Decode order vs display order: can differ when B-frames are used.
- YUV formats: common video formats; chroma subsampling reduces color resolution.

## Codec Standards

| Standard | Practical Notes |
| --- | --- |
| H.264 / AVC | Very widely supported, mature hardware acceleration, lower complexity. |
| H.265 / HEVC | Better compression than H.264, higher complexity, strong hardware support on modern devices. |
| VP9 | Open codec, used heavily in web video, generally better compression than H.264. |
| AV1 | Strong compression, royalty-free design goal, higher encode complexity, growing hardware support. |
| VVC / H.266 | Newer and more efficient, high complexity, less universal deployment. |

Interview framing:

> I would choose a codec based on hardware support, latency target, bandwidth, power, quality target, and platform constraints.

## Low-Latency Streaming Tradeoffs

- B-frames improve compression but can increase latency.
- Smaller GOP helps error recovery but raises bitrate.
- Larger buffers smooth network jitter but increase latency.
- Aggressive compression saves bandwidth but increases encode/decode cost and artifacts.
- Hardware encode/decode reduces CPU cost but can add API, copy, and synchronization constraints.
- GPU readback can destroy latency if the pipeline blocks waiting for data.
- Frame pacing can be bad even if average FPS looks fine.

Good answer pattern:

> I would measure glass-to-glass latency by stage, then optimize the largest contributor without breaking quality or stability.

## C++ Systems Topics

Review:

- RAII and deterministic cleanup
- `unique_ptr`, `shared_ptr`, raw pointer ownership boundaries
- Move semantics and avoiding unnecessary copies
- Object lifetime across async work
- Alignment and cache locality
- False sharing
- Stack vs heap allocation
- Undefined behavior and data races
- ABI/API boundaries in SDK-style code

## Concurrency Topics

Know how to explain:

- Mutex vs atomic
- Condition variable usage
- Producer-consumer queue
- Ring buffer / circular buffer
- Work queues and thread pools
- Deadlock prevention
- Lock contention
- Backpressure
- Memory ordering at a high level

Producer-consumer answer outline:

1. Define bounded capacity.
2. Keep read index, write index, and count.
3. Protect shared state with a mutex or use atomics for a lock-free design only if justified.
4. Use condition variables if producers/consumers should block.
5. Validate empty, full, wraparound, shutdown, and stress cases.

## GPU / Graphics Topics

Review:

- Compute shaders
- CUDA kernels, blocks, threads, shared memory, reductions
- Vulkan command buffers, queues, fences, semaphores, barriers
- HLSL resource binding, UAV/SRV concepts, thread groups
- Texture formats and render targets
- RGB/YUV conversion and scaling
- GPU-to-CPU readback stalls
- Async compute and copy queues
- Memory bandwidth and occupancy

Strong answer pattern:

> The first thing I check is whether the CPU is waiting on the GPU, the GPU is starved by the CPU, or both are waiting on synchronization or memory movement.

## Debugging And Profiling Checklist

For a performance problem:

1. Reproduce with a stable test case.
2. Define the target: FPS, latency, bitrate, memory, CPU, GPU, or quality.
3. Add timestamps around every pipeline stage.
4. Split CPU time, GPU time, queue wait time, copy time, and network time.
5. Inspect queue depth and frame drops.
6. Look for blocking waits and unnecessary copies.
7. Optimize one bottleneck at a time.
8. Re-test with regression coverage.

Tools to mention if applicable:

- Visual Studio debugger/profiler
- RenderDoc
- PIX
- Nsight Systems / Nsight Compute
- GPUView
- logs, traces, counters, and custom timestamps

## Existing Repo Practice Mapping

- Frame budget: `questions/coderpad_rendering/Q14_Frame_Budget_CPU_GPU_Bottleneck.cpp`
- Texture memory: `questions/coderpad_rendering/Q13_Texture_RenderTarget_Memory_Cost.cpp`
- Ring buffer: `questions/data_structure_builder/Q15_Implement_Circular_Buffer_Queue.cpp`
- CUDA memory bandwidth: `CUDA practice/Project_04_CUDA_Array_Reduction`
- CUDA parallel decomposition: `CUDA practice/Project_07_CUDA_Fourier_Analysis`
