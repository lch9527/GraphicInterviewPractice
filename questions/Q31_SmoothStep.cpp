// Run: .\build\Debug\Q31_SmoothStep.exe
/*
Question 31: SmoothStep

Description:
Implement smoothstep between edge0 and edge1.

Task:
Implement this function:
    float SmoothStep(float edge0, float edge1, float x);

How to run this file:
    g++ -std=c++17 -I../include Q31_SmoothStep.cpp -o q31 && ./q31

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

float SmoothStep(float edge0, float edge1, float x) {
    // TODO: implement this function.
    return 0.0f;
}

bool RunTests() {

    EXPECT_NEAR(SmoothStep(0,10,0), 0.0f);
    EXPECT_NEAR(SmoothStep(0,10,10), 1.0f);
    EXPECT_NEAR(SmoothStep(0,10,5), 0.5f);
    EXPECT_NEAR(SmoothStep(0,10,-5), 0.0f);
    EXPECT_NEAR(SmoothStep(0,10,15), 1.0f);

    return true;
}

RUN_TESTS()

