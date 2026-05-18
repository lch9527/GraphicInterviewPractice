// Build: cmake --build build --config Debug --target Q04_Compute_Dot_Product
// Run: .\build\Debug\Q04_Compute_Dot_Product.exe
/*
Question 4: Compute Dot Product

Description:
Given two vectors, return their dot product.

Task:
Implement this function:
    float Dot(const Vec3& a, const Vec3& b);

How to run this file:
    g++ -std=c++17 -I../include Q04_Compute_Dot_Product.cpp -o q04 && ./q04

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

float Dot(const Vec3& a, const Vec3& b) {
    // TODO: implement this function.
    return 0.0f;
}

bool RunTests() {

    EXPECT_NEAR(Dot({1,0,0}, {0,1,0}), 0.0f);
    EXPECT_NEAR(Dot({1,2,3}, {4,5,6}), 32.0f);
    EXPECT_NEAR(Dot({1,0,0}, {-1,0,0}), -1.0f);

    return true;
}

RUN_TESTS()


