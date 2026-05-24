/*
CoderPad Rendering Question 4: Triangle Normal and Facing Camera

Calculate a triangle normal and test whether the triangle faces the camera.
This is a CoderPad-focused variation of the existing triangle questions.
*/

#include "MathTypes.h"
#include <iostream>

Vec3 CalculateTriangleNormal(const Vec3& a, const Vec3& b, const Vec3& c) {
    // TODO: use winding order: normal = normalize(cross(b - a, c - a)).
    return NormalizeHelper(CrossHelper(b - a, c - a));
}

bool IsTriangleFacingCamera(const Vec3& a, const Vec3& b, const Vec3& c, const Vec3& cameraPos) {
    // TODO: compute triangle center, direction to camera, then dot with normal.
    Vec3 normal = CalculateTriangleNormal(a, b, c);
    Vec3 center = (a + b + c) / 3.0f;
    Vec3 viewDir = NormalizeHelper(cameraPos - center);
    return DotHelper(normal, viewDir) > 0.0f;
}

bool RunTests() {
    EXPECT_VEC3(CalculateTriangleNormal({0,0,0}, {1,0,0}, {0,1,0}), Vec3{0,0,1});
    EXPECT_VEC3(CalculateTriangleNormal({0,0,0}, {0,1,0}, {1,0,0}), Vec3{0,0,-1});
    EXPECT_TRUE(IsTriangleFacingCamera({0,0,0}, {1,0,0}, {0,1,0}, {0,0,5}));
    EXPECT_FALSE(IsTriangleFacingCamera({0,0,0}, {1,0,0}, {0,1,0}, {0,0,-5}));
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q04 Triangle Normal Facing Camera\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
The normal sign depends on winding order. With viewDir from surface to camera,
a positive dot means the surface normal points toward the camera.
*/
