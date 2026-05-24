/*
CoderPad Rendering Question 14: Frame Budget and CPU/GPU Bottleneck

Implement simple frame budget and bottleneck detection helpers.
*/

#include "MathTypes.h"
#include <algorithm>
#include <cstring>
#include <iostream>

float FrameBudgetMs(int fps) {
    // TODO: convert frames per second to milliseconds per frame.
    return 1000.0f / static_cast<float>(fps);
}

bool IsFrameOverBudget(float cpuFrameMs, float gpuFrameMs, float targetFps) {
    // TODO: simple frame time is the slower of CPU and GPU frame times.
    float frameTime = std::max(cpuFrameMs, gpuFrameMs);
    return frameTime > (1000.0f / targetFps);
}

const char* DetectBottleneck(float cpuFrameMs, float gpuFrameMs) {
    // TODO: use a small tolerance to avoid overclassifying near-equal timings.
    constexpr float toleranceMs = 0.25f;
    if (cpuFrameMs > gpuFrameMs + toleranceMs) return "CPU-bound";
    if (gpuFrameMs > cpuFrameMs + toleranceMs) return "GPU-bound";
    return "balanced/mixed";
}

bool RunTests() {
    EXPECT_NEAR(FrameBudgetMs(60), 16.666666f);
    EXPECT_NEAR(FrameBudgetMs(90), 11.111111f);
    EXPECT_NEAR(FrameBudgetMs(120), 8.333333f);
    EXPECT_FALSE(IsFrameOverBudget(8.0f, 10.0f, 60.0f));
    EXPECT_TRUE(IsFrameOverBudget(8.0f, 18.0f, 60.0f));
    EXPECT_TRUE(std::strcmp(DetectBottleneck(18.0f, 10.0f), "CPU-bound") == 0);
    EXPECT_TRUE(std::strcmp(DetectBottleneck(8.0f, 12.0f), "GPU-bound") == 0);
    EXPECT_TRUE(std::strcmp(DetectBottleneck(10.0f, 10.1f), "balanced/mixed") == 0);
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q14 Frame Budget CPU GPU Bottleneck\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
Frame rate is limited by the slower side of the CPU/GPU pipeline. A 60 FPS
target gives about 16.67 ms, while 90 and 120 FPS require tighter budgets.
*/
