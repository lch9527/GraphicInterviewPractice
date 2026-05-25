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
    Vec3 totarget = NormalizeHelper(targetPos - actorPos);

    float helffovR = (fovDegrees/2) * 3.1415926 / 180;

    float dotValue = dot(totarget,actorForward);

    float cosHelfFov = cos(helffovR);

    return dotValue >= cosHelfFov;


}

bool RunTests() {

    EXPECT_TRUE(IsInsideFOV({0,0,0}, {1,0,0}, {10,1,0}, 60.0f));
    EXPECT_FALSE(IsInsideFOV({0,0,0}, {1,0,0}, {0,10,0}, 60.0f));
    EXPECT_FALSE(IsInsideFOV({0,0,0}, {1,0,0}, {-1,0,0}, 120.0f));

    return true;
}

RUN_TESTS()


