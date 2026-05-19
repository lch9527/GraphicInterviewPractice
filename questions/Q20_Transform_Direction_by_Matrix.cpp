// Build: cmake --build build --config Debug --target Q20_Transform_Direction_by_Matrix
// Run: .\build\Debug\Q20_Transform_Direction_by_Matrix.exe
/*
Question 20: Transform Direction by Matrix

Description:
Transform a direction by a 4x4 matrix using w=0. Translation must not affect direction.

Task:
Implement this function:
    Vec3 TransformDirection(const Mat4& m, const Vec3& dir);

How to run this file:
    g++ -std=c++17 -I../include Q20_Transform_Direction_by_Matrix.cpp -o q20 && ./q20

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec3 TransformDirection(const Mat4& m, const Vec3& dir) {
    // TODO: implement this function.
    Mat4 transposed = m;
    Vec4 homogeneousPoint = Vec4{dir.x, dir.y, dir.z, 0.0f};  
    Vec4 transformedPoint = Vec4{
        transposed.m[0][0] * homogeneousPoint.x + transposed.m[0][1] * homogeneousPoint.y + transposed.m[0][2] * homogeneousPoint.z,
        transposed.m[1][0] * homogeneousPoint.x + transposed.m[1][1] * homogeneousPoint.y + transposed.m[1][2] * homogeneousPoint.z,
        transposed.m[2][0] * homogeneousPoint.x + transposed.m[2][1] * homogeneousPoint.y + transposed.m[2][2] * homogeneousPoint.z,
    };
    return Vec3{transformedPoint.x, transformedPoint.y, transformedPoint.z};
}

bool RunTests() {

    Mat4 t = Identity4(); t.m[0][3] = 10.0f;
    EXPECT_VEC3(TransformDirection(t, {0,0,1}), Vec3{0,0,1});
    Mat4 s = Identity4(); s.m[0][0] = 2.0f; s.m[1][1] = 3.0f; s.m[2][2] = 4.0f;
    EXPECT_VEC3(TransformDirection(s, {1,2,3}), Vec3{2,6,12});

    return true;
}

RUN_TESTS()


