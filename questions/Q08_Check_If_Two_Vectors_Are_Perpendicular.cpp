// Run: .\build\Debug\Q08_Check_If_Two_Vectors_Are_Perpendicular.exe
/*
Question 8: Check If Two Vectors Are Perpendicular

Description:
Return true if two vectors are perpendicular. Use epsilon.

Task:
Implement this function:
    bool ArePerpendicular(const Vec3& a, const Vec3& b);

How to run this file:
    g++ -std=c++17 -I../include Q08_Check_If_Two_Vectors_Are_Perpendicular.cpp -o q08 && ./q08

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

bool ArePerpendicular(const Vec3& a, const Vec3& b) {
    // TODO: implement this function.
    return false;
}

bool RunTests() {

    EXPECT_TRUE(ArePerpendicular({1,0,0}, {0,1,0}));
    EXPECT_FALSE(ArePerpendicular({1,0,0}, {1,0,0}));
    EXPECT_TRUE(ArePerpendicular({1,2,0}, {-2,1,0}));

    return true;
}

RUN_TESTS()

