// Run: .\build\Debug\Q29_Linear_Interpolation.exe
/*
Question 29: Linear Interpolation

Description:
Implement scalar lerp: a + (b-a)*t.

Task:
Implement this function:
    float Lerp(float a, float b, float t);

How to run this file:
    g++ -std=c++17 -I../include Q29_Linear_Interpolation.cpp -o q29 && ./q29

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

float Lerp(float a, float b, float t) {
    // TODO: implement this function.
    return 0.0f;
}

bool RunTests() {

    EXPECT_NEAR(Lerp(10,20,0.0f), 10.0f);
    EXPECT_NEAR(Lerp(10,20,1.0f), 20.0f);
    EXPECT_NEAR(Lerp(10,20,0.5f), 15.0f);

    return true;
}

RUN_TESTS()

