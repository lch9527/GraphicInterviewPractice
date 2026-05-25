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
    // TODO: return the angle in degrees. Return 0 for zero-length input.
    (void)a;
    (void)b;
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

/*
Interview explanation:
The normalized dot product gives cos(theta). Clamp the value before acos to
avoid NaN from tiny floating-point error outside [-1, 1].
*/
