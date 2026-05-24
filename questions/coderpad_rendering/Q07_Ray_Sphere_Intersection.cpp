/*
CoderPad Rendering Question 7: Ray-Sphere Intersection

Return the nearest positive ray-sphere intersection distance. This is a
CoderPad-focused variation of the existing ray-sphere question.
*/

#include "MathTypes.h"
#include <iostream>

bool RaySphereIntersection(const Vec3& rayOrigin, const Vec3& rayDir, const Vec3& sphereCenter,
                           float sphereRadius, float& outT) {
    // TODO: build and solve the quadratic equation.
    Vec3 oc = rayOrigin - sphereCenter;
    float a = DotHelper(rayDir, rayDir);
    float b = 2.0f * DotHelper(oc, rayDir);
    float c = DotHelper(oc, oc) - sphereRadius * sphereRadius;
    float discriminant = b * b - 4.0f * a * c;
    if (discriminant < 0.0f) return false;

    float sqrtDisc = std::sqrt(discriminant);
    float t0 = (-b - sqrtDisc) / (2.0f * a);
    float t1 = (-b + sqrtDisc) / (2.0f * a);
    if (t0 >= 0.0f) { outT = t0; return true; }
    if (t1 >= 0.0f) { outT = t1; return true; }
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
