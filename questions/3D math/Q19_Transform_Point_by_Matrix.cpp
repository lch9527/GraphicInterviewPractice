// Run from this file directory:
//   mkdir -p "../../questions_artifacts/3D math" && g++ -std=c++17 -I../../include Q19_Transform_Point_by_Matrix.cpp -o "../../questions_artifacts/3D math/3d_math_q19" && "../../questions_artifacts/3D math/3d_math_q19"

// Build: cmake --build build --config Debug --target Q19_Transform_Point_by_Matrix
// Run: .\build\Debug\Q19_Transform_Point_by_Matrix.exe
/*
Question 19: Transform Point by Matrix

Description:
Transform a point by a 4x4 matrix using w=1. Perform perspective divide if needed.

Task:
Implement this function:
    Vec3 TransformPoint(const Mat4& m, const Vec3& p);

How to run this file:
    g++ -std=c++17 -I../../include Q19_Transform_Point_by_Matrix.cpp -o q19 && ./q19

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec3 TransformPoint(const Mat4& m, const Vec3& p) {
    Vec4 transformed = Mul(m, Vec4{p.x, p.y, p.z, 1.0f});

    if (std::fabs(transformed.w) > EPSILON) {
        transformed.x /= transformed.w;
        transformed.y /= transformed.w;
        transformed.z /= transformed.w;
    }

    return Vec3{transformed.x, transformed.y, transformed.z};
}

bool RunTests() {

    Mat4 t = Identity4(); t.m[3][0] = 10.0f;
    EXPECT_VEC3(TransformPoint(t, {1,2,3}), Vec3{11,2,3});
    Mat4 s = Identity4(); s.m[0][0] = 2.0f; s.m[1][1] = 3.0f; s.m[2][2] = 4.0f;
    EXPECT_VEC3(TransformPoint(s, {1,2,3}), Vec3{2,6,12});

    return true;
}

RUN_TESTS()
