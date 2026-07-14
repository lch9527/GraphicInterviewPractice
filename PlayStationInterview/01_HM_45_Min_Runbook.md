# HM 45-Minute Interview Runbook

Interviewers:

- Seema Kataria, Manager, Software Engineering
- Jason Wang, Sr. Manager, SW Engineering

Format:

- Virtual Microsoft Teams
- 45 minutes
- Expected focus: experience, technical depth, ownership, communication, and fit for codec / SDK / cloud gaming work

## Goal

Convince them of four things:

1. You can own end-to-end engineering work: design, implementation, validation, and debugging.
2. You are strong in C/C++, graphics/GPU programming, concurrency, and low-level performance.
3. You can reason about latency-sensitive pipelines even if codec-standard details require ramp-up.
4. You communicate clearly with managers and cross-functional engineers.

## Suggested 45-Minute Flow

If they drive the interview, follow their lead. If they ask open-ended questions, use this pacing:

- 0-3 min: short intro
- 3-20 min: one or two deep technical project stories
- 20-32 min: technical discussion
- 32-38 min: behavioral / ownership discussion
- 38-45 min: your questions

## 30-Second Intro

Use this structure, then personalize it:

> I am a C++ and graphics/systems engineer with hands-on work in real-time rendering concepts, GPU programming, CUDA-style parallel workloads, and debugging performance-sensitive code. My strongest areas are low-level implementation, profiling, and explaining complex technical problems clearly. This role interests me because PlayStation codec and cloud gaming work sits at the intersection of C/C++, GPU acceleration, timing, memory bandwidth, and end-to-end validation.

If they ask "why this role":

> The role is not only codec implementation. The JD emphasizes SDK components, cloud gaming platforms, system-level performance analysis, GPU/graphics programming, debugging, and cross-team collaboration. Those are the areas where my background maps well. I also see codec-specific standards like AV1, VP9, H.265, and H.264 as a focused ramp area, not a blocker.

## High-Probability Questions

### "Tell us about your experience."

Answer in this order:

1. C++ / systems base
2. Graphics or GPU work
3. Performance / debugging
4. End-to-end ownership
5. Why that maps to PlayStation codec/cloud gaming

Do not walk through the resume line by line.

### "What is your strongest technical project?"

Use a single project and go deep:

- What was the system?
- What did you own?
- What made it hard?
- What performance or correctness problem appeared?
- How did you isolate it?
- What changed in the implementation?
- How did you validate the fix?
- What was the result?

### "How would you debug a video pipeline performance problem?"

Answer framework:

1. Define the symptom: frame drops, latency spike, quality drop, GPU stall, CPU saturation.
2. Add timestamps at each stage: capture, convert, encode, packetize, network, decode, render.
3. Separate CPU time, GPU time, queue wait time, copy time, and network jitter.
4. Check queue depth and backpressure.
5. Inspect synchronization points: GPU readback, resource barriers, blocking waits, lock contention.
6. Optimize only after measurement.
7. Validate with latency, frame pacing, quality, and regression tests.

### "What if you do not have deep codec experience?"

Say this directly and bridge:

> My deepest experience is in C++, graphics/GPU programming, and performance debugging. I have been studying codec fundamentals: frame types, prediction, transforms, quantization, entropy coding, rate control, and low-latency streaming tradeoffs. I would ramp by first understanding the team's existing pipeline and validation tools, then taking ownership of bounded issues where my debugging and GPU/system skills are immediately useful.

## Behavioral Answer Framework

Use STAR, but keep it technical:

- Situation: one sentence
- Task: what you owned
- Action: concrete technical and communication steps
- Result: measurable result or clear outcome
- Lesson: one sentence

Avoid vague claims like "I worked hard" or "I collaborated well." Show evidence.

## Things To Emphasize

- You measure before optimizing.
- You know CPU/GPU boundaries matter.
- You can debug timing and concurrency issues.
- You validate features, not just implement them.
- You can work with hardware/platform/system software engineers.
- You can explain tradeoffs clearly to managers.

## Things To Avoid

- Do not overclaim direct codec expertise if it is not true.
- Do not answer only with algorithms; this job is systems-heavy.
- Do not make assumptions about the interviewers beyond their titles.
- Do not spend time re-selling the resume; they already selected you for HM review.
