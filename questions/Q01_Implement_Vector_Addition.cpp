// Run: .\build\Debug\Q01_Implement_Vector_Addition.exe
/*
Question 1: Implement Vector Addition

Description:
Given two 3D vectors a and b, return their sum.

Task:
Implement this function:
    Vec3 Add(const Vec3& a, const Vec3& b);

How to run this file:
    g++ -std=c++17 -I../include Q01_Implement_Vector_Addition.cpp -o q01 && ./q01

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec3 Add(const Vec3& a, const Vec3& b) {
    // TODO: implement this function.
    Vec3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;

    return result;
}

bool RunTests() {

    EXPECT_VEC3(Add({1,2,3}, {4,5,6}), Vec3{5,7,9});
    EXPECT_VEC3(Add({-1,2,0}, {1,-2,5}), Vec3{0,0,5});

    return true;
}

RUN_TESTS()

