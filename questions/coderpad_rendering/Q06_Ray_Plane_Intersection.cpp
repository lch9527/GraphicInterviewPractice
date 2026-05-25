// Run from this file directory:
//   mkdir -p ../../questions_artifacts/coderpad_rendering && g++ -std=c++17 -I../../include Q06_Ray_Plane_Intersection.cpp -o ../../questions_artifacts/coderpad_rendering/coderpad_q06 && ../../questions_artifacts/coderpad_rendering/coderpad_q06

/*
CoderPad Rendering Question 6: Ray-Plane Intersection

Task:
Implement ray-plane intersection and return whether the hit is in front of the ray.

Concepts tested:
- ray equation P = O + tD
- plane equation dot(N, X) + d = 0
- parallel ray handling
- t >= 0 hit check
*/

#include "MathTypes.h"
#include <iostream>

constexpr float LOCAL_EPSILON = 1e-6f;

bool RayPlaneIntersection(const Vec3& rayOrigin, const Vec3& rayDir,
                          const Vec3& planeNormal, const Vec3& pointOnPlane,
                          float& outT) {
/*
    dot(o+dt - p, n) = 0;
    dot(n,op+dt) = 0
    dot(n,op) + dot(n,dt) = 0
    dot(n,op) + t*dot(n,d) = 0
    t = -dot(n,op)/dot(n,d);
*/
    float dome = dot(planeNormal, rayDir);
    if (fabs(dome) < 0.0001){
        return false;
    }

    outT = -dot(planeNormal,rayOrigin - pointOnPlane)/dome;

    return outT > 0.00001;
}

/*

*/

bool RunTests() {
    float t = -1.0f;
    EXPECT_TRUE(RayPlaneIntersection({0,0,0}, {0,1,0}, {0,1,0}, {0,5,0}, t));
    EXPECT_NEAR(t, 5.0f);
    EXPECT_FALSE(RayPlaneIntersection({0,0,0}, {1,0,0}, {0,1,0}, {0,5,0}, t));
    EXPECT_FALSE(RayPlaneIntersection({0,0,0}, {0,-1,0}, {0,1,0}, {0,5,0}, t));
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q06 Ray Plane Intersection\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
The denominator dot(N, D) tells whether the ray points toward the plane. If it
is near zero, the ray is parallel and cannot produce a stable intersection.
*/
