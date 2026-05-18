// Build: cmake --build build --config Debug --target Q35_Check_If_Point_Is_Inside_Rectangle
// Run: .\build\Debug\Q35_Check_If_Point_Is_Inside_Rectangle.exe
/*
Question 35: Check If Point Is Inside Rectangle

Description:
Given point and rect min/max, return true if point is inside inclusive bounds.

Task:
Implement this function:
    bool PointInRect(const Vec2& p, const Vec2& rectMin, const Vec2& rectMax);

How to run this file:
    g++ -std=c++17 -I../include Q35_Check_If_Point_Is_Inside_Rectangle.cpp -o q35 && ./q35

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

bool PointInRect(const Vec2& p, const Vec2& rectMin, const Vec2& rectMax) {
    // TODO: implement this function.
    return false;
}

bool RunTests() {

    EXPECT_TRUE(PointInRect({5,5}, {0,0}, {10,10}));
    EXPECT_TRUE(PointInRect({0,0}, {0,0}, {10,10}));
    EXPECT_FALSE(PointInRect({-1,5}, {0,0}, {10,10}));
    EXPECT_FALSE(PointInRect({5,11}, {0,0}, {10,10}));

    return true;
}

RUN_TESTS()


