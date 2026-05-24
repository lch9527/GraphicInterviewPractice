/*
CoderPad Rendering Question 9: Sphere Frustum Culling

Given six frustum planes and a bounding sphere, return whether the sphere is
inside or intersecting the frustum. This is a CoderPad-focused variation of the
existing frustum sphere question.
*/

#include "MathTypes.h"
#include <iostream>

struct Sphere {
    Vec3 center;
    float radius = 0.0f;
};

bool SphereInFrustum(const Plane planes[6], const Sphere& sphere) {
    // TODO: cull only when the sphere is fully outside any plane.
    for (int i = 0; i < 6; ++i) {
        float distance = DotHelper(planes[i].normal, sphere.center) + planes[i].d;
        if (distance < -sphere.radius) return false;
    }
    return true;
}

bool RunTests() {
    Plane planes[6] = {
        {{1,0,0}, 1}, {{-1,0,0}, 1},
        {{0,1,0}, 1}, {{0,-1,0}, 1},
        {{0,0,1}, 1}, {{0,0,-1}, 1}
    };
    EXPECT_TRUE(SphereInFrustum(planes, {{0,0,0}, 0.5f}));
    EXPECT_TRUE(SphereInFrustum(planes, {{1.2f,0,0}, 0.3f}));
    EXPECT_FALSE(SphereInFrustum(planes, {{2.0f,0,0}, 0.5f}));
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q09 Sphere Frustum Culling\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
Negative signed distance means the center is outside a plane. A sphere is only
rejected when that distance is more negative than its radius.
*/
