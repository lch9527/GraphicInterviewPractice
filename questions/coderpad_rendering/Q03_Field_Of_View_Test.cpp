/*
CoderPad Rendering Question 3: Field Of View Cone Test

Task:
Given an actor position, forward direction, target position, and FOV angle,
return whether the target is inside the actor's FOV cone.

Concepts tested:
- forward and to-target vectors
- normalized dot product
- avoiding acos
- degree-to-radian conversion
*/

#include "MathTypes.h"
#include <iostream>

constexpr float LOCAL_PI = 3.1415926535f;
constexpr float LOCAL_EPSILON = 1e-6f;

bool IsTargetInFOV(const Vec3& actorPos, const Vec3& actorForward,
                   const Vec3& targetPos, float fovDegrees) {
    Vec3 totarget = NormalizeHelper(targetPos - actorPos);
    Vec3 Forward = NormalizeHelper(actorForward);

    if(LengthHelper(totarget) < LOCAL_EPSILON || LengthHelper(Forward) < LOCAL_EPSILON){
        return false;
    }

    float dotresult = dot(totarget ,Forward);

    if (dotresult > 1){
        dotresult = 1;
    }
    if (dotresult < -1){
        dotresult = -1;
    }

    float helfr = fovDegrees/2 * LOCAL_PI/180;
    
    float threshold = cos(helfr);

    return dotresult >= threshold;

}

bool RunTests() {
    EXPECT_TRUE(IsTargetInFOV({0,0,0}, {0,0,1}, {0,0,5}, 90.0f));
    EXPECT_TRUE(IsTargetInFOV({0,0,0}, {0,0,1}, {1,0,1}, 90.0f));
    EXPECT_FALSE(IsTargetInFOV({0,0,0}, {0,0,1}, {5,0,0}, 90.0f));
    EXPECT_FALSE(IsTargetInFOV({0,0,0}, {0,0,0}, {0,0,5}, 90.0f));
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
cos(halfFOV) avoids the cost and edge cases of acos.
*/
