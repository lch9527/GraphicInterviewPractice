// Build: cmake --build build --config Debug --target Q23_Build_Camera_Basis
// Run: .\build\Debug\Q23_Build_Camera_Basis.exe
/*
Question 23: Build Camera Basis

Description:
Given eye, target, and worldUp, calculate forward, right, and up. Use right-handed convention in prompt.

Task:
Implement this function:
    CameraBasis BuildCameraBasis(const Vec3& eye, const Vec3& target, const Vec3& worldUp);

How to run this file:
    g++ -std=c++17 -I../include Q23_Build_Camera_Basis.cpp -o q23 && ./q23

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

CameraBasis BuildCameraBasis(const Vec3& eye, const Vec3& target, const Vec3& worldUp) {

    Vec3 forward = NormalizeHelper(target - eye);
    Vec3 right = NormalizeHelper( cross(forward,worldUp));
    Vec3 up = NormalizeHelper(cross(right,forward));
    // TODO: implement this function.

    return {forward,right,up};
}

bool RunTests() {

    CameraBasis b = BuildCameraBasis({0,0,0}, {0,0,-1}, {0,1,0});
    EXPECT_VEC3(b.forward, Vec3{0,0,-1});
    EXPECT_VEC3(b.right, Vec3{1,0,0});
    EXPECT_VEC3(b.up, Vec3{0,1,0});

    return true;
}

RUN_TESTS()


