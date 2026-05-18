// Build: cmake --build build --config Debug --target Q02_Implement_Vector_Subtraction
// Run: .\build\Debug\Q02_Implement_Vector_Subtraction.exe
/*
Question 2: Implement Vector Subtraction

Description:
Given two 3D vectors a and b, return a - b.

Task:
Implement this function:
    Vec3 Subtract(const Vec3& a, const Vec3& b);

How to run this file:
    g++ -std=c++17 -I../include Q02_Implement_Vector_Subtraction.cpp -o q02 && ./q02

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec3 Subtract(const Vec3& a, const Vec3& b) {
    // TODO: implement this function.
    Vec3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

bool RunTests() {

    EXPECT_VEC3(Subtract({5,7,9}, {1,2,3}), Vec3{4,5,6});
    EXPECT_VEC3(Subtract({0,0,0}, {1,-2,5}), Vec3{-1,2,-5});

    return true;
}

RUN_TESTS()


