// Build: cmake --build build --config Debug --target Q16_Distance_Between_Two_Points
// Run: .\build\Debug\Q16_Distance_Between_Two_Points.exe
/*
Question 16: Distance Between Two Points

Description:
Return distance between two 3D points.

Task:
Implement this function:
    float Distance(const Vec3& a, const Vec3& b);

How to run this file:
    g++ -std=c++17 -I../include Q16_Distance_Between_Two_Points.cpp -o q16 && ./q16

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

float Distance(const Vec3& a, const Vec3& b) {
    // TODO: implement this function.
    Vec3 AB = b - a;
    float result = sqrt(AB.x*AB.x + AB.y*AB.y + AB.z*AB.z);
    return result;
}

bool RunTests() {

    EXPECT_NEAR(Distance({0,0,0}, {3,4,0}), 5.0f);
    EXPECT_NEAR(Distance({1,2,3}, {1,2,3}), 0.0f);

    return true;
}

RUN_TESTS()


