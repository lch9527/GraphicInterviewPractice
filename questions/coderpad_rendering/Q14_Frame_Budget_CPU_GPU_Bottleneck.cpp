// Run from this file directory:
//   mkdir -p ../../questions_artifacts/coderpad_rendering && g++ -std=c++17 -I../../include Q14_Frame_Budget_CPU_GPU_Bottleneck.cpp -o ../../questions_artifacts/coderpad_rendering/coderpad_q14 && ../../questions_artifacts/coderpad_rendering/coderpad_q14

/*
CoderPad Rendering Question 14: Frame Budget and CPU/GPU Bottleneck

Task:
Implement simple frame budget and bottleneck detection helpers.

Concepts tested:
- frame pacing
- CPU-bound vs GPU-bound
- 60/90/120 FPS budgets
- rendering performance reasoning
*/

#include "MathTypes.h"
#include <iostream>
#include <string>

constexpr float LOCAL_EPSILON_MS = 0.25f;

float FrameBudgetMs(int fps) {
    // TODO: implement this function.
    return 0.0f;
}

bool IsFrameOverBudget(float cpuFrameMs, float gpuFrameMs, float targetFps) {
    // TODO: implement this function.
    return false;
}

const char* DetectBottleneck(float cpuFrameMs, float gpuFrameMs) {
    // TODO: implement this function.
    return "";
}

bool RunTests() {
    EXPECT_NEAR(FrameBudgetMs(60), 16.666666f);
    EXPECT_NEAR(FrameBudgetMs(90), 11.111111f);
    EXPECT_NEAR(FrameBudgetMs(120), 8.333333f);
    EXPECT_TRUE(IsFrameOverBudget(10.0f, 17.0f, 60.0f));
    EXPECT_FALSE(IsFrameOverBudget(8.0f, 10.0f, 60.0f));
    EXPECT_TRUE(std::string(DetectBottleneck(12.0f, 8.0f)) == "CPU-bound");
    EXPECT_TRUE(std::string(DetectBottleneck(8.0f, 12.0f)) == "GPU-bound");
    EXPECT_TRUE(std::string(DetectBottleneck(10.0f, 10.1f)) == "Balanced");
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q14 Frame Budget CPU GPU Bottleneck\n";
    return ok ? 0 : 1;
}

