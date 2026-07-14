# Story Bank

Fill these in before the interview. Keep each spoken answer under 3 minutes unless they ask for more detail.

## Story 1: Graphics / GPU / Performance

Use this for questions about GPU programming, profiling, optimization, or real-time systems.

Project:

- Name:
- Context:
- My role:
- Technologies:
- Performance target:

Problem:

- What was slow, incorrect, or risky?
- Why did it matter?
- What constraints existed?

Technical details:

- CPU work:
- GPU work:
- Memory / bandwidth concern:
- Synchronization concern:
- Data layout:
- Profiling tools or timing method:

Action:

- How I reproduced the issue:
- What I measured:
- What I changed:
- Why that change was correct:
- How I validated it:

Result:

- Latency / throughput / correctness result:
- What I learned:

Suggested projects from this repo:

- `CUDA practice/Project_04_CUDA_Array_Reduction`: memory bandwidth, reductions, block size, profiling.
- `CUDA practice/Project_07_CUDA_Fourier_Analysis`: parallel scan-style workload and GPU decomposition.
- `questions/coderpad_rendering/Q14_Frame_Budget_CPU_GPU_Bottleneck.cpp`: frame budget reasoning.

## Story 2: C++ / Systems / Concurrency

Use this for questions about C++, multithreading, queues, low-level debugging, or reliability.

Project:

- Name:
- Context:
- My role:
- C++ features used:

Problem:

- What made the system complex?
- Was the issue race, deadlock, lifetime bug, memory pressure, or latency?
- How did it appear in logs/tests/profiling?

Technical details:

- Shared state:
- Ownership model:
- Synchronization primitive:
- Queue or buffer design:
- Failure mode:

Action:

- How I narrowed the issue:
- What invariant I defined:
- What implementation changed:
- How I tested edge cases:

Result:

- Correctness result:
- Performance result:
- What I would improve next:

Suggested projects from this repo:

- `questions/data_structure_builder/Q15_Implement_Circular_Buffer_Queue.cpp`: ring buffer and producer-consumer discussion.
- `questions/leetcode/Prompt_Q06_Design_Circular_Queue.cpp`: circular queue API tradeoffs.

## Story 3: Hard Bug

Question examples:

- "Tell me about a difficult bug."
- "How do you debug complex systems?"
- "Tell me about a time you were stuck."

Template:

> We saw [symptom]. My first step was to make the failure reproducible and define what "correct" meant. I added/used [logs, timestamps, profiler, debugger, assertions] and split the system into [components]. The key clue was [observation]. The root cause was [specific technical cause]. I fixed it by [specific change], then validated with [tests, profiling, stress case]. The result was [outcome].

## Story 4: Cross-Team Collaboration

Question examples:

- "Tell me about working with another team."
- "How do you handle disagreement?"
- "How do you communicate technical tradeoffs?"

Template:

> The disagreement was about [tradeoff]. I separated the problem into goals, constraints, and measurable risk. I proposed [small experiment / data collection / design doc]. After we had data, the decision became [decision]. My contribution was [technical work plus communication]. The result was [team result].

## Story 5: Ownership Under Ambiguity

Question examples:

- "Tell me about a time requirements were unclear."
- "How do you own a feature end to end?"

Template:

> The initial ask was [ambiguous request]. I clarified success criteria as [criteria], identified risks around [risk], and proposed a small implementation plan. I delivered [design/implementation/validation], kept stakeholders updated through [method], and closed the loop with [tests/results/docs].

## Story 6: Learning a New Technical Area

Use this if codec experience comes up.

Template:

> I usually ramp by building a working mental model first, then mapping it to the actual codebase. For codec work, I would start with the pipeline stages and validation tools, then learn the team's use of standards like H.264/H.265/AV1 in context. I would look for a bounded bug or performance issue where my C++/GPU/debugging skills create value while I deepen codec-specific knowledge.
