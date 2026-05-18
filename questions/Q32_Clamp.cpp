// Build: cmake --build build --config Debug --target Q32_Clamp
// Run: .\build\Debug\Q32_Clamp.exe
/*
Question 32: Clamp

Description:
Return x clamped into [minValue, maxValue].

Task:
Implement this function:
    float Clamp(float x, float minValue, float maxValue);

How to run this file:
    g++ -std=c++17 -I../include Q32_Clamp.cpp -o q32 && ./q32

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

float Clamp(float x, float minValue, float maxValue) {
    // TODO: implement this function.
    return 0.0f;
}

bool RunTests() {

    EXPECT_NEAR(Clamp(12,0,10), 10.0f);
    EXPECT_NEAR(Clamp(-2,0,10), 0.0f);
    EXPECT_NEAR(Clamp(5,0,10), 5.0f);

    return true;
}

RUN_TESTS()


