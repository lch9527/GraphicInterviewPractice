// Build: cmake --build build --config Debug --target Q27_Ray-Sphere_Intersection
// Run: .\build\Debug\Q27_Ray-Sphere_Intersection.exe
/*
Question 27: Ray-Sphere Intersection

Description:
Given ray and sphere, return true if hit and output nearest positive t.

Task:
Implement this function:
    bool RaySphereIntersection(const Vec3& rayOrigin, const Vec3& rayDir, const Vec3& sphereCenter, float sphereRadius, float& outT);

How to run this file:
    g++ -std=c++17 -I../include Q27_Ray-Sphere_Intersection.cpp -o q27 && ./q27

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

bool RaySphereIntersection(const Vec3& rayOrigin, const Vec3& rayDir, const Vec3& sphereCenter, float sphereRadius, float& outT) {
    Vec3 oc = rayOrigin - sphereCenter;

    float a = dot(rayDir, rayDir);
    float b = 2.0f * dot(oc, rayDir);
    float c = dot(oc, oc) - sphereRadius * sphereRadius;

    float discriminant = b * b - 4.0f * a * c;
    if (discriminant < 0.0f) {
        return false;
    }

    float sqrtDiscriminant = std::sqrt(discriminant);
    float t0 = (-b - sqrtDiscriminant) / (2.0f * a);
    float t1 = (-b + sqrtDiscriminant) / (2.0f * a);

    if (t0 >= 0.0f) {
        outT = t0;
        return true;
    }

    if (t1 >= 0.0f) {
        outT = t1;
        return true;
    }

    return false;
}

bool RunTests() {

    float t = 0.0f;
    EXPECT_TRUE(RaySphereIntersection({0,0,0}, {0,0,1}, {0,0,5}, 1.0f, t));
    EXPECT_NEAR(t, 4.0f);
    EXPECT_FALSE(RaySphereIntersection({0,0,0}, {0,1,0}, {0,0,5}, 1.0f, t));
    EXPECT_TRUE(RaySphereIntersection({0,0,5}, {0,0,1}, {0,0,5}, 1.0f, t));
    EXPECT_NEAR(t, 1.0f);

    return true;
}

RUN_TESTS()



/*
  dot(oc + D * t, oc + D * t) = r^2

  dot(oc,oc) + 2dot(oc,d*t) + dot(d*t,d*t) = r^2

  dot(oc,oc) + t*2 dot(oc,d) + t^2*dot(d,d) - r^2 = 0

  a = dot(d,d)
  b = 2 * dot(oc,d)
  c = dot(oc,oc) - r * 2

*/