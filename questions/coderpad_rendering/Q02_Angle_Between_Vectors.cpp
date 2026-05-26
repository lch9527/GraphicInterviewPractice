// Run from this file directory:
//   mkdir -p ../../questions_artifacts/coderpad_rendering && g++ -std=c++17 -I../../include Q02_Angle_Between_Vectors.cpp -o ../../questions_artifacts/coderpad_rendering/coderpad_q02 && ../../questions_artifacts/coderpad_rendering/coderpad_q02

/*
CoderPad Rendering Question 2: Angle Between Vectors

Task:
Given two vectors, return the angle between them in degrees.

Concepts tested:
- dot product
- acos
- radians-to-degrees conversion
- clamping before acos
- zero-length vector handling
*/

#include "MathTypes.h"
#include <iostream>

constexpr float LOCAL_PI = 3.1415926535f;
constexpr float LOCAL_EPSILON = 1e-6f;

float AngleBetweenDegrees(const Vec3& a, const Vec3& b) {
    // TODO: implement this function.
    return 0.0f;
}

bool RunTests() {
    EXPECT_NEAR(AngleBetweenDegrees({1,0,0}, {1,0,0}), 0.0f);
    EXPECT_NEAR(AngleBetweenDegrees({1,0,0}, {0,1,0}), 90.0f);
    EXPECT_NEAR(AngleBetweenDegrees({1,0,0}, {-1,0,0}), 180.0f);
    EXPECT_NEAR(AngleBetweenDegrees({0,0,0}, {1,0,0}), 0.0f);
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q02 Angle Between Vectors\n";
    return ok ? 0 : 1;
}

