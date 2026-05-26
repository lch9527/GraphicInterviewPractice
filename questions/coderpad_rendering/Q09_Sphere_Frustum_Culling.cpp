/*
CoderPad Rendering Question 9: Sphere Frustum Culling

Task:
Given 6 frustum planes and a bounding sphere, return whether the sphere is
inside or intersecting the frustum.

Concepts tested:
- frustum culling
- signed plane distance
- conservative bounding sphere visibility
*/

#include "MathTypes.h"
#include <iostream>

struct Sphere {
    Vec3 center;
    float radius = 0.0f;
};

bool SphereInFrustum(const Plane planes[6], const Sphere& sphere) {
    // TODO: reject only when signed distance is less than -sphere.radius.
    for (int i = 0; i < 6; i++) {
        float distance = dot(planes[i].normal, sphere.center) + planes[i].d;
        if (distance < -sphere.radius) {
            return false;
        }
    }
    return true;
}

bool RunTests() {
    Plane planes[6] = {
        {{ 1, 0, 0}, 1}, {{-1, 0, 0}, 1},
        {{ 0, 1, 0}, 1}, {{ 0,-1, 0}, 1},
        {{ 0, 0, 1}, 1}, {{ 0, 0,-1}, 1}
    };

    EXPECT_TRUE(SphereInFrustum(planes, {{0,0,0}, 0.5f}));
    EXPECT_TRUE(SphereInFrustum(planes, {{1.2f,0,0}, 0.3f}));
    EXPECT_TRUE(SphereInFrustum(planes, {{1.3f,0,0}, 0.3f}));
    EXPECT_FALSE(SphereInFrustum(planes, {{2.0f,0,0}, 0.3f}));
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q09 Sphere Frustum Culling\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
Negative distance means the center is outside a plane, but the sphere may still
intersect the frustum. Cull only when it is farther outside than its radius.
*/
