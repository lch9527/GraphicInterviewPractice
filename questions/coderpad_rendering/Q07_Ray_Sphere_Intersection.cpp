/*
CoderPad Rendering Question 7: Ray-Sphere Intersection

Task:
Implement ray-sphere intersection and return the nearest positive t.

Concepts tested:
- ray equation
- sphere equation
- quadratic equation
- discriminant
- choosing nearest positive intersection
*/

#include "MathTypes.h"
#include <iostream>

bool RaySphereIntersection(const Vec3& rayOrigin, const Vec3& rayDir,
                           const Vec3& sphereCenter, float sphereRadius,
                           float& outT) {
    // TODO: build the quadratic coefficients and solve for the nearest positive t.
    (void)rayOrigin;
    (void)rayDir;
    (void)sphereCenter;
    (void)sphereRadius;
    outT = 0.0f;
    return false;
}

bool RunTests() {
    float t = -1.0f;
    EXPECT_TRUE(RaySphereIntersection({0,0,0}, {0,0,1}, {0,0,5}, 1.0f, t));
    EXPECT_NEAR(t, 4.0f);
    EXPECT_FALSE(RaySphereIntersection({0,0,0}, {0,1,0}, {0,0,5}, 1.0f, t));
    EXPECT_TRUE(RaySphereIntersection({0,0,5}, {0,0,1}, {0,0,5}, 1.0f, t));
    EXPECT_NEAR(t, 1.0f);
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q07 Ray Sphere Intersection\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
The discriminant tells whether the ray misses, touches, or passes through the
sphere. Use the smaller non-negative t for the closest visible hit.
*/
