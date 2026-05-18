// Build: cmake --build build --config Debug --target Q03_Implement_Scalar_Multiplication
// Run: .\build\Debug\Q03_Implement_Scalar_Multiplication.exe
/*
Question 3: Implement Scalar Multiplication

Description:
Given a vector v and scalar s, return v * s.

Task:
Implement this function:
    Vec3 Multiply(const Vec3& v, float s);

How to run this file:
    g++ -std=c++17 -I../include Q03_Implement_Scalar_Multiplication.cpp -o q03 && ./q03

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec3 Multiply(const Vec3& v, float s) {
    // TODO: implement this function.
    return {};
}

bool RunTests() {

    EXPECT_VEC3(Multiply({1,2,3}, 2.0f), Vec3{2,4,6});
    EXPECT_VEC3(Multiply({-1,0.5f,3}, -2.0f), Vec3{2,-1,-6});

    return true;
}

RUN_TESTS()


