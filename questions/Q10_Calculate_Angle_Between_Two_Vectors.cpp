// Build: cmake --build build --config Debug --target Q10_Calculate_Angle_Between_Two_Vectors
// Run: .\build\Debug\Q10_Calculate_Angle_Between_Two_Vectors.exe
/*
Question 10: Calculate Angle Between Two Vectors

Description:
Return the angle between vectors in degrees.

Task:
Implement this function:
    float AngleBetweenDegrees(const Vec3& a, const Vec3& b);

How to run this file:
    g++ -std=c++17 -I../include Q10_Calculate_Angle_Between_Two_Vectors.cpp -o q10 && ./q10

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

float AngleBetweenDegrees(const Vec3& a, const Vec3& b) {
    // TODO: implement this function.
    return 0.0f;
}

bool RunTests() {

    EXPECT_NEAR(AngleBetweenDegrees({1,0,0}, {0,1,0}), 90.0f);
    EXPECT_NEAR(AngleBetweenDegrees({1,0,0}, {1,0,0}), 0.0f);
    EXPECT_NEAR(AngleBetweenDegrees({1,0,0}, {-1,0,0}), 180.0f);

    return true;
}

RUN_TESTS()


