// Run from this file directory:
//   mkdir -p ../../questions_artifacts/coderpad_rendering && g++ -std=c++17 -I../../include Q05_Transform_Point_vs_Direction.cpp -o ../../questions_artifacts/coderpad_rendering/coderpad_q05 && ../../questions_artifacts/coderpad_rendering/coderpad_q05

/*
CoderPad Rendering Question 5: TransformPoint vs TransformDirection

Task:
Implement TransformPoint and TransformDirection.

Concepts tested:
- homogeneous coordinates
- points use w = 1
- directions use w = 0
- translation affects points but not directions
*/

#include "MathTypes.h"
#include <iostream>

Vec3 TransformPoint(const Mat4& m, const Vec3& p) {
    Vec4 res = Mul(m, Vec4{p.x, p.y, p.z, 1.0f});
    if (std::fabs(res.w) > EPSILON && !AlmostEqual(res.w, 1.0f)) {
        res.x /= res.w;
        res.y /= res.w;
        res.z /= res.w;
    }

    return {res.x, res.y, res.z};
}

Vec3 TransformDirection(const Mat4& m, const Vec3& dir) {
    Vec4 res = Mul(m, Vec4{dir.x, dir.y, dir.z, 0.0f});
    return {res.x, res.y, res.z};
}

Mat4 MakeTranslation(float x, float y, float z) {
    Mat4 m = Identity4();
    m.m[3][0] = x;
    m.m[3][1] = y;
    m.m[3][2] = z;
    return m;
}

bool RunTests() {
    Mat4 translation = MakeTranslation(10.0f, 20.0f, 30.0f);
    EXPECT_VEC3(TransformPoint(translation, {1,2,3}), Vec3{11,22,33});
    EXPECT_VEC3(TransformDirection(translation, {1,2,3}), Vec3{1,2,3});

    Mat4 scale = Identity4();
    scale.m[0][0] = 2.0f;
    scale.m[1][1] = 3.0f;
    scale.m[2][2] = 4.0f;
    EXPECT_VEC3(TransformPoint(scale, {1,2,3}), Vec3{2,6,12});
    EXPECT_VEC3(TransformDirection(scale, {1,2,3}), Vec3{2,6,12});
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q05 Transform Point vs Direction\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
TransformPoint applies rotation, scale, and translation. TransformDirection
applies rotation and scale, but ignores translation because w is 0.
*/
