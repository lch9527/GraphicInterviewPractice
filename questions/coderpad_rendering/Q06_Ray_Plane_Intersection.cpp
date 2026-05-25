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
    // TODO: use planeD and normalDotRayDir to solve for t.
    float dotr = dot(NormalizeHelper(rayDir), planeNormal);
    if (abs(dotr) < 0.001){
        return false;
    }

    Vec3 toplane = pointOnPlane - rayOrigin;

    outT = dot(planeNormal,toplane) / dotr;
    if(outT < 0){
        return false;
    }

    return true;
}

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
