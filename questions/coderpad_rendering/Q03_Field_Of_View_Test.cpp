/*
CoderPad Rendering Question 3: Field Of View Cone Test

Return whether a target is inside an actor's FOV cone. This is a CoderPad-focused
variation of the existing FOV question.
*/

#include "MathTypes.h"
#include <iostream>

constexpr float PI = 3.1415926535f;

bool IsTargetInFOV(const Vec3& actorPos, const Vec3& actorForward, const Vec3& targetPos, float fovDegrees) {
    // TODO: compare dot(normalized forward, normalized toTarget) with cos(half FOV).
    Vec3 toTarget = NormalizeHelper(targetPos - actorPos);
    Vec3 forward = NormalizeHelper(actorForward);
    float halfFOV = fovDegrees * 0.5f;
    float threshold = std::cos(halfFOV * PI / 180.0f);
    return DotHelper(forward, toTarget) >= threshold;
}

bool RunTests() {
    EXPECT_TRUE(IsTargetInFOV({0,0,0}, {1,0,0}, {10,0,0}, 90.0f));
    EXPECT_TRUE(IsTargetInFOV({0,0,0}, {1,0,0}, {10,10,0}, 90.0f));
    EXPECT_FALSE(IsTargetInFOV({0,0,0}, {1,0,0}, {0,10,0}, 90.0f));
    EXPECT_FALSE(IsTargetInFOV({0,0,0}, {1,0,0}, {-1,0,0}, 180.0f));
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q03 Field Of View Test\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
For normalized vectors, dot product gives cos(theta). Comparing against
cos(halfFOV) avoids the more expensive acos call.
*/
