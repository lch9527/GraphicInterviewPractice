/*
CoderPad Rendering Question 5: TransformPoint vs TransformDirection

Implement point and direction transformation. This is a CoderPad-focused
variation of the existing matrix transform questions.
*/

#include "MathTypes.h"
#include <iostream>

Vec3 TransformPoint(const Mat4& m, const Vec3& p) {
    // TODO: transform with w = 1 and divide by w when needed.
    Vec4 input{p.x, p.y, p.z, 1.0f};
    Vec4 r = Mul(m, input);
    if (std::fabs(r.w) > EPSILON && !AlmostEqual(r.w, 1.0f)) {
        return {r.x / r.w, r.y / r.w, r.z / r.w};
    }
    return {r.x, r.y, r.z};
}

Vec3 TransformDirection(const Mat4& m, const Vec3& dir) {
    // TODO: transform with w = 0 so translation is ignored.
    Vec4 input{dir.x, dir.y, dir.z, 0.0f};
    Vec4 r = Mul(m, input);
    return {r.x, r.y, r.z};
}

bool RunTests() {
    Mat4 t = Identity4();
    t.m[0][3] = 10.0f;
    t.m[1][3] = -2.0f;
    Mat4 s = Identity4();
    s.m[0][0] = 2.0f;
    s.m[1][1] = 3.0f;
    s.m[2][2] = 4.0f;
    EXPECT_VEC3(TransformPoint(t, {1,2,3}), Vec3{11,0,3});
    EXPECT_VEC3(TransformDirection(t, {1,2,3}), Vec3{1,2,3});
    EXPECT_VEC3(TransformPoint(s, {1,2,3}), Vec3{2,6,12});
    EXPECT_VEC3(TransformDirection(s, {1,2,3}), Vec3{2,6,12});
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q05 Transform Point vs Direction\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
Points use w = 1, so translation applies. Directions use w = 0, so only the
upper-left 3x3 rotation/scale portion affects them.
*/
