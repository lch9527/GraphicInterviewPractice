# C++ For Interview Cheat Sheet

Use this for the practical C++ side of the role.

## What They Likely Care About

For this role, C++ questions are likely about:

- memory ownership
- performance
- object lifetime
- concurrency safety
- low-level correctness

This is more important than obscure language trivia.

## Topics To Be Comfortable With

### Ownership

Know the difference between:

- stack vs heap
- owning vs non-owning pointers
- `unique_ptr` vs `shared_ptr`

Good interview sentence:

> I try to make ownership obvious so lifetime bugs are easier to avoid and debug.

### RAII

Resource Acquisition Is Initialization means tying resource cleanup to object lifetime.

Why it matters:

- prevents leaks
- makes cleanup deterministic
- safer in complex systems

### Move Semantics

Moving avoids unnecessary copies for expensive objects.

High-level point:

- moving transfers ownership or internal state efficiently

### Const Correctness

Shows intent and helps prevent accidental modification.

### References vs Pointers

At interview level, the main point is clarity of ownership, nullability, and API intent.

## Performance Concepts

Important practical ideas:

- copies can be expensive
- data layout affects cache behavior
- allocation patterns matter
- smaller critical sections reduce contention

Good interview sentence:

> In performance-sensitive C++ code, the data layout and ownership model often matter as much as the algorithm.

## Common Bug Types

- use-after-free
- dangling pointer
- double free
- data race
- lifetime mismatch across threads
- hidden copy cost

## Good Practical Phrases

> I try to make lifetime and ownership explicit because many low-level bugs come from unclear ownership boundaries.

> When performance matters, I think about copies, allocations, cache behavior, and synchronization overhead together.

## What They Probably Do Not Need

You likely do not need:

- obscure template metaprogramming details
- extreme standard-library trivia
- advanced compile-time tricks

Unless the interviewer steers there, stay practical.

## Safe Honest Answer

> My C++ focus is on writing correct, maintainable low-level code with clear ownership, careful resource management, and attention to performance characteristics.
