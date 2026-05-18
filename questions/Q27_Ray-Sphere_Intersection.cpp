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
    // TODO: implement this function.
    outT = 0.0f; return false;
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


