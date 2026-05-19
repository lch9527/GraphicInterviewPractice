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
    g++ -std=c++17 -I../include Q19_Transform_Point_by_Matrix.cpp -o q19 && ./q19

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec3 TransformPoint(const Mat4& m, const Vec3& p) {
    // TODO: implement this function.
    Mat4 transposed = m;
    Vec4 homogeneousPoint = Vec4{p.x, p.y, p.z, 1.0f};  
    Vec4 transformedPoint = Vec4{
        transposed.m[0][0] * homogeneousPoint.x + transposed.m[0][1] * homogeneousPoint.y + transposed.m[0][2] * homogeneousPoint.z + transposed.m[0][3] * homogeneousPoint.w,
        transposed.m[1][0] * homogeneousPoint.x + transposed.m[1][1] * homogeneousPoint.y + transposed.m[1][2] * homogeneousPoint.z + transposed.m[1][3] * homogeneousPoint.w,
        transposed.m[2][0] * homogeneousPoint.x + transposed.m[2][1] * homogeneousPoint.y + transposed.m[2][2] * homogeneousPoint.z + transposed.m[2][3] * homogeneousPoint.w,
        transposed.m[3][0] * homogeneousPoint.x + transposed.m[3][1] * homogeneousPoint.y + transposed.m[3][2] * homogeneousPoint.z + transposed.m[3][3] * homogeneousPoint.w       
    };
    /*
    1 0 0 10
    0 1 0 0
    0 0 1 0
    0 0 0 1
    
    */
    if (transformedPoint.w != 0.0f) {
        transformedPoint.x /= transformedPoint.w;
        transformedPoint.y /= transformedPoint.w;
        transformedPoint.z /= transformedPoint.w;
    }
    return Vec3{transformedPoint.x, transformedPoint.y, transformedPoint.z};    
}

bool RunTests() {

    Mat4 t = Identity4(); t.m[0][3] = 10.0f;
    EXPECT_VEC3(TransformPoint(t, {1,2,3}), Vec3{11,2,3});
    Mat4 s = Identity4(); s.m[0][0] = 2.0f; s.m[1][1] = 3.0f; s.m[2][2] = 4.0f;
    EXPECT_VEC3(TransformPoint(s, {1,2,3}), Vec3{2,6,12});

    return true;
}

RUN_TESTS()


