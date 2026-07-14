# Mock Questions

Use these for spoken practice. Do not memorize full paragraphs. Practice answering with structure.

## HM Interview Questions

1. Tell us about yourself.
   - Answer with C++ systems, graphics/GPU, performance/debugging, and why this role.

2. Why Sony Interactive Entertainment / PlayStation?
   - Mention player-scale technical problems, SDK/platform work, cloud gaming, and real-time performance.

3. Why this codec/cloud gaming role?
   - Connect C++, GPU, profiling, concurrency, and latency-sensitive systems.

4. Walk us through a complex technical project.
   - Use problem, ownership, architecture, bottleneck, fix, validation, result.

5. Tell us about a performance optimization you owned.
   - Show measurement before optimization.

6. Tell us about a difficult debugging problem.
   - Show reproduction, instrumentation, hypothesis, root cause, fix, validation.

7. How do you work with hardware, platform, or system software teams?
   - Show interface clarity, logs/data, shared repro, and tradeoff communication.

8. What is your experience with GPU programming?
   - Mention CUDA/HLSL/Vulkan concepts honestly and go deep on one project.

9. How would you ramp up on codec standards?
   - Explain a concrete ramp plan, not vague enthusiasm.

10. What kind of engineering work do you want to do next?
   - Keep it aligned with low-level systems, performance, SDKs, GPU, and cloud gaming.

## Technical Panel Questions

1. Design a low-latency cloud gaming video pipeline.
   - Include render, capture, color conversion, encode, packetize, transmit, receive, decode, display, input loop.

2. How would you debug frame drops in a cloud gaming session?
   - Use staged timestamps and queue-depth analysis.

3. CPU time is 6 ms, GPU time is 14 ms, target is 60 FPS. Are we over budget?
   - 60 FPS budget is about 16.67 ms. Not over budget if pipelined correctly, but GPU is the bottleneck.

4. CPU time is 18 ms, GPU time is 8 ms, target is 60 FPS. What is the bottleneck?
   - CPU-bound and over budget.

5. Explain mutex vs atomic.
   - Mutex protects larger critical sections; atomic protects simple shared values and requires memory-order reasoning.

6. Design a bounded producer-consumer queue.
   - Include capacity, read/write indices, wraparound, empty/full, blocking or non-blocking behavior, shutdown.

7. What is false sharing?
   - Independent data on the same cache line causing cache invalidation between cores.

8. Why can GPU readback be expensive?
   - It can force synchronization and stall CPU/GPU parallelism.

9. What is a resource barrier in Vulkan-style APIs?
   - A synchronization/visibility transition so later GPU work sees resources in the correct state.

10. Explain H.264 vs H.265 vs AV1 at a practical level.
    - Discuss compression, complexity, hardware support, and latency/platform tradeoffs.

11. Why might B-frames be bad for low latency?
    - They can require future frames and add reordering delay.

12. How do you validate a codec SDK feature?
    - Correctness, bitstream compatibility, quality, latency, performance, stress, regression, hardware coverage.

13. How would you find a memory bandwidth bottleneck?
    - Measure throughput, inspect copies, data layout, cache behavior, GPU memory transactions, and profiler counters.

14. How do you avoid deadlocks?
    - Lock ordering, smaller critical sections, timeouts where appropriate, no blocking callbacks while holding locks.

15. How would you debug a race condition?
    - Repro/stress, logging with thread IDs/timestamps, sanitizers if available, reduce shared state, assert invariants.

## Behavioral Mock Questions

1. Tell me about a time you owned a feature end to end.
2. Tell me about a time requirements were unclear.
3. Tell me about a time you disagreed with another engineer.
4. Tell me about a time you had to learn a new technical area quickly.
5. Tell me about a time you made a mistake.
6. Tell me about a time you improved performance.

## Self-Scoring Checklist

After each answer, score 0 or 1 for each:

- Did I answer the question directly?
- Did I give concrete technical details?
- Did I explain my personal ownership?
- Did I mention validation or results?
- Did I connect the answer to PlayStation role signals?

Target score: 4 or 5.
