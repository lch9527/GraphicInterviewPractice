// Run: .\build\Debug\Q05_Compute_Cross_Product.exe
/*
Question 5: Compute Cross Product

Description:
Given two 3D vectors, return their cross product.

Task:
Implement this function:
    Vec3 Cross(const Vec3& a, const Vec3& b);

How to run this file:
    g++ -std=c++17 -I../include Q05_Compute_Cross_Product.cpp -o q05 && ./q05

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec3 Cross(const Vec3& a, const Vec3& b) {
    // TODO: implement this function.
    return {};
}

bool RunTests() {

    EXPECT_VEC3(Cross({1,0,0}, {0,1,0}), Vec3{0,0,1});
    EXPECT_VEC3(Cross({0,1,0}, {1,0,0}), Vec3{0,0,-1});
    EXPECT_VEC3(Cross({1,2,3}, {4,5,6}), Vec3{-3,6,-3});

    return true;
}

RUN_TESTS()

