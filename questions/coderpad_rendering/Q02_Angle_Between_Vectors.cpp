/*
CoderPad Rendering Question 2: Angle Between Vectors

Return the angle between two vectors in degrees. This is a CoderPad-focused
variation of the existing angle question.
*/

#include "MathTypes.h"
#include <algorithm>
#include <iostream>

constexpr float PI = 3.1415926535f;
constexpr float LOCAL_EPSILON = 1e-6f;

float AngleBetweenDegrees(const Vec3& a, const Vec3& b) {
    // TODO: use dot, lengths, clamp, acos, then convert radians to degrees.
    float lenA = LengthHelper(a);
    float lenB = LengthHelper(b);
    if (lenA < LOCAL_EPSILON || lenB < LOCAL_EPSILON) return 0.0f;

    float cosTheta = DotHelper(a, b) / (lenA * lenB);
    cosTheta = std::max(-1.0f, std::min(1.0f, cosTheta));
    return std::acos(cosTheta) * 180.0f / PI;
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
Clamp before acos because floating-point rounding can push a mathematically
valid cosine slightly outside [-1, 1].
*/
