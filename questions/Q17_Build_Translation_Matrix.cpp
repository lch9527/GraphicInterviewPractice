// Build: cmake --build build --config Debug --target Q17_Build_Translation_Matrix
// Run: .\build\Debug\Q17_Build_Translation_Matrix.exe
/*
Question 17: Build Translation Matrix

Description:
Build a column-major Mat4 for column-vector style multiplication, with translation in m[3][0],m[3][1],m[3][2].

Task:
Implement this function:
    Mat4 MakeTranslation(float tx, float ty, float tz);

How to run this file:
    g++ -std=c++17 -I../include Q17_Build_Translation_Matrix.cpp -o q17 && ./q17

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Mat4 MakeTranslation(float tx, float ty, float tz) {
    // TODO: implement this function.
    Mat4 result = Identity4();
    result.m[3][0] = tx;
    result.m[3][1] = ty;
    result.m[3][2] = tz;
    return result;
}

bool RunTests() {

    Mat4 expected = Identity4();
    expected.m[3][0] = 10.0f; expected.m[3][1] = 2.0f; expected.m[3][2] = -3.0f;
    EXPECT_TRUE(AlmostEqual(MakeTranslation(10.0f, 2.0f, -3.0f), expected));

    return true;
}

RUN_TESTS()

