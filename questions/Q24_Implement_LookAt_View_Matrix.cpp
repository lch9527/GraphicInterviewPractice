// Run: .\build\Debug\Q24_Implement_LookAt_View_Matrix.exe
/*
Question 24: Implement LookAt View Matrix

Description:
Return a view matrix for right-handed camera looking from eye to target. Row-major, column-vector style.

Task:
Implement this function:
    Mat4 LookAt(const Vec3& eye, const Vec3& target, const Vec3& worldUp);

How to run this file:
    g++ -std=c++17 -I../include Q24_Implement_LookAt_View_Matrix.cpp -o q24 && ./q24

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Mat4 LookAt(const Vec3& eye, const Vec3& target, const Vec3& worldUp) {
    // TODO: implement this function.
    return {};
}

bool RunTests() {

    Mat4 v = LookAt({0,0,5}, {0,0,0}, {0,1,0});
    Vec4 worldOrigin{0,0,0,1};
    Vec4 viewOrigin = Mul(v, worldOrigin);
    EXPECT_NEAR(viewOrigin.x, 0.0f);
    EXPECT_NEAR(viewOrigin.y, 0.0f);
    EXPECT_NEAR(viewOrigin.z, -5.0f);
    EXPECT_NEAR(viewOrigin.w, 1.0f);

    return true;
}

RUN_TESTS()

