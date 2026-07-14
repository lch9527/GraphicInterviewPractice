# Codec Interview Cheat Sheet

Use this as a one-page review sheet for the PlayStation interview.

## What a Codec Is

A video codec is a system for compressing and decompressing video.

- `co` = compress / code
- `dec` = decompress / decode

Why it exists:

- Raw video is huge.
- Compression makes storage and streaming practical.
- The decoder reconstructs the video for playback.

Good interview sentence:

> A codec is the technology that compresses video into a smaller bitstream and then decodes it for playback.

## What a Codec Standard Is

A codec standard is a rulebook for how compressed video is represented so encoders and decoders can interoperate.

Examples:

- `H.264 / AVC`
- `H.265 / HEVC`
- `VP9`
- `AV1`

Good interview sentence:

> Codec standards like H.264, H.265, VP9, and AV1 define the rules for compressing and decoding video, with different tradeoffs in efficiency, latency, hardware support, and complexity.

## High-Level Idea Of How Compression Works

Video codecs reduce data by exploiting patterns:

- parts of the frame that do not change
- movement between frames
- details humans notice less

You do not need spec-level detail. Just know:

- video is not compressed only frame-by-frame as isolated images
- codecs often use information from previous or nearby frames

## The Four Standards At A Practical Level

### H.264 / AVC

- older, very common, widely supported
- strong compatibility across devices and platforms
- less efficient than newer codecs

Good phrase:

> H.264 is the widely supported baseline codec and is often the safest compatibility choice.

### H.265 / HEVC

- newer than H.264
- better compression efficiency
- common for higher-resolution video like 4K
- more complexity and licensing concerns

Good phrase:

> H.265 usually gives better compression than H.264, but it can come with more complexity and licensing tradeoffs.

### VP9

- Google-backed
- common in web video, especially YouTube
- generally better compression than H.264
- older than AV1

Good phrase:

> VP9 is a widely used web-focused codec that improved compression over H.264 and was an important step before AV1.

### AV1

- newer open codec
- very strong compression efficiency
- attractive for modern streaming
- heavier computational cost, especially encoding

Good phrase:

> AV1 is attractive because it can deliver high quality at lower bitrates, but the compute cost is higher and hardware support matters.

## The Real Tradeoffs

Do not memorize obscure details. Learn these tradeoffs:

- better compression can reduce bandwidth
- better compression may require more compute
- lower latency is critical for cloud gaming
- hardware support can matter more than theoretical quality
- compatibility still matters in production systems

Best summary sentence:

> The practical tradeoff is usually between compression efficiency, latency, computational cost, hardware support, and compatibility.

## Why Cloud Gaming Cares

In cloud gaming, video is interactive, so latency matters a lot.

Codec choices affect:

- bandwidth usage
- image quality
- encode/decode speed
- end-to-end latency
- CPU/GPU utilization
- device support

Good interview sentence:

> In cloud gaming, the best codec is not just the one with the best compression. It also has to fit latency, hardware, and platform constraints.

## What They Probably Expect You To Know

- what a codec is
- what a codec standard is
- basic difference between H.264, H.265, VP9, and AV1
- why low latency matters for cloud gaming
- why hardware acceleration matters
- why better compression is not automatically better for real-time systems

## What They Probably Do Not Expect

Unless your resume claims deep codec work, they probably do not expect:

- bitstream syntax details
- formal standard internals
- exact partitioning rules
- entropy coding details
- writing an encoder from scratch

## Safe Honest Answer If Asked About Codec Depth

> My strongest background is in C++, systems, GPU-related work, and performance/debugging. On codecs, I understand the practical level: standards like H.264, H.265, VP9, and AV1 are different approaches to video compression with tradeoffs in bitrate efficiency, latency, hardware support, and computational cost. For a cloud gaming system, I would focus on how those tradeoffs affect end-to-end latency, quality, and platform constraints.

## Three Things Not To Mess Up

- Do not pretend deep codec expertise if you do not have it.
- Do not confuse codec with container like MP4 or MKV.
- Do not talk only about quality and ignore latency.
