// Build: cmake --build build --config Debug --target Q18_Build_Scale_Matrix
// Run: .\build\Debug\Q18_Build_Scale_Matrix.exe
/*
Question 18: Build Scale Matrix

Description:
Build a 4x4 scale matrix.

Task:
Implement this function:
    Mat4 MakeScale(float sx, float sy, float sz);

How to run this file:
    g++ -std=c++17 -I../include Q18_Build_Scale_Matrix.cpp -o q18 && ./q18

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Mat4 MakeScale(float sx, float sy, float sz) {
     Mat4 result = Identity4();
    result.m[0][0] = sx;
    result.m[1][1] = sy;
    result.m[2][2] = sz;
    return result;
}

bool RunTests() {

    Mat4 expected = Identity4();
    expected.m[0][0] = 2.0f; expected.m[1][1] = 3.0f; expected.m[2][2] = 4.0f;
    EXPECT_TRUE(AlmostEqual(MakeScale(2.0f, 3.0f, 4.0f), expected));

    return true;
}

RUN_TESTS()


