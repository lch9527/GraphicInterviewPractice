// Build: cmake --build build --config Debug --target Q21_Compose_Transform_Matrix
// Run: .\build\Debug\Q21_Compose_Transform_Matrix.exe
/*
Question 21: Compose Transform Matrix

Description:
Build a 2D-style transform matrix using T * Rz * S. Column-vector style.

Task:
Implement this function:
    Mat4 MakeTransform2D(const Vec3& translation, float rotationRadians, const Vec3& scale);

How to run this file:
    g++ -std=c++17 -I../include Q21_Compose_Transform_Matrix.cpp -o q21 && ./q21

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Mat4 MakeTransform2D(const Vec3& translation, float rotationRadians, const Vec3& scale) {
    // TODO: implement this function.
    return {};
}

bool RunTests() {

    Mat4 m = MakeTransform2D({10,0,0}, PI_F / 2.0f, {2,2,1});
    Vec4 p{1,0,0,1};
    Vec4 out = Mul(m, p);
    EXPECT_NEAR(out.x, 10.0f);
    EXPECT_NEAR(out.y, 2.0f);
    EXPECT_NEAR(out.z, 0.0f);
    EXPECT_NEAR(out.w, 1.0f);

    return true;
}

RUN_TESTS()


