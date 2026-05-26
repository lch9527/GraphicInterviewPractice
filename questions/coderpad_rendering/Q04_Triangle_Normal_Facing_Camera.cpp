// Run from this file directory:
//   mkdir -p ../../questions_artifacts/coderpad_rendering && g++ -std=c++17 -I../../include Q04_Triangle_Normal_Facing_Camera.cpp -o ../../questions_artifacts/coderpad_rendering/coderpad_q04 && ../../questions_artifacts/coderpad_rendering/coderpad_q04

/*
CoderPad Rendering Question 4: Triangle Normal and Facing Camera

Task:
1. Calculate a triangle normal.
2. Check whether the triangle faces the camera.

Concepts tested:
- cross product
- winding order
- triangle center
- view direction
- dot product facing test
*/

#include "MathTypes.h"
#include <iostream>

Vec3 CalculateTriangleNormal(const Vec3& a, const Vec3& b, const Vec3& c) {
    return NormalizeHelper(cross(b-a,c-a));
}

bool IsTriangleFacingCamera(const Vec3& a, const Vec3& b, const Vec3& c,
                            const Vec3& cameraPos) {
    Vec3 normal = CalculateTriangleNormal(a, b, c);
    Vec3 center = (a + b + c) / 3.0f;
    Vec3 viewDir = NormalizeHelper(cameraPos - center);

    return dot(normal, viewDir) > 0.0f;
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
Winding order controls normal direction. If viewDir points from the surface to
the camera, a positive dot(normal, viewDir) means the triangle faces the camera.
*/
