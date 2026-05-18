// Build: cmake --build build --config Debug --target Q11_Check_If_Target_Is_Inside_Field_of_View
// Run: .\build\Debug\Q11_Check_If_Target_Is_Inside_Field_of_View.exe
/*
Question 11: Check If Target Is Inside Field of View

Description:
Given actor position, forward, target position, and FOV degrees, return whether target is inside the FOV cone.

Task:
Implement this function:
    bool IsInsideFOV(const Vec3& actorPos, const Vec3& actorForward, const Vec3& targetPos, float fovDegrees);

How to run this file:
    g++ -std=c++17 -I../include Q11_Check_If_Target_Is_Inside_Field_of_View.cpp -o q11 && ./q11

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

bool IsInsideFOV(const Vec3& actorPos, const Vec3& actorForward, const Vec3& targetPos, float fovDegrees) {
    // TODO: implement this function.
    Vec3 toTarget = {targetPos.x - actorPos.x, targetPos.y - actorPos.y, targetPos.z - actorPos.z};
    float helffov = fovDegrees / 2.0f;
    Vec3 newActorForward = NormalizeHelper(actorForward);
    Vec3 newToTarget = NormalizeHelper(toTarget);
    float dot = Dot(newActorForward, newToTarget);
    dot = std::clamp(dot, -1.0f, 1.0f);
    float angle = std::acos(dot) * 180.0f / M_PI;
    
    if (angle <= helffov) {
        return true;
    }
    return false;
}

bool RunTests() {

    EXPECT_TRUE(IsInsideFOV({0,0,0}, {1,0,0}, {10,1,0}, 60.0f));
    EXPECT_FALSE(IsInsideFOV({0,0,0}, {1,0,0}, {0,10,0}, 60.0f));
    EXPECT_FALSE(IsInsideFOV({0,0,0}, {1,0,0}, {-1,0,0}, 120.0f));

    return true;
}

RUN_TESTS()


