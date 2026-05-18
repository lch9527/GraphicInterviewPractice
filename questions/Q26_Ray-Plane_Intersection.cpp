// Build: cmake --build build --config Debug --target Q26_Ray-Plane_Intersection
// Run: .\build\Debug\Q26_Ray-Plane_Intersection.exe
/*
Question 26: Ray-Plane Intersection

Description:
Given a ray and plane defined by normal + point, return whether they intersect and output t.

Task:
Implement this function:
    bool RayPlaneIntersection(const Vec3& rayOrigin, const Vec3& rayDir, const Vec3& planeNormal, const Vec3& pointOnPlane, float& outT);

How to run this file:
    g++ -std=c++17 -I../include Q26_Ray-Plane_Intersection.cpp -o q26 && ./q26

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

bool RayPlaneIntersection(const Vec3& rayOrigin, const Vec3& rayDir, const Vec3& planeNormal, const Vec3& pointOnPlane, float& outT) {
    // TODO: implement this function.
    outT = 0.0f; return false;
}

bool RunTests() {

    float t = 0.0f;
    EXPECT_TRUE(RayPlaneIntersection({0,0,0}, {0,1,0}, {0,1,0}, {0,5,0}, t));
    EXPECT_NEAR(t, 5.0f);
    EXPECT_FALSE(RayPlaneIntersection({0,0,0}, {1,0,0}, {0,1,0}, {0,5,0}, t));
    EXPECT_FALSE(RayPlaneIntersection({0,0,0}, {0,-1,0}, {0,1,0}, {0,5,0}, t));

    return true;
}

RUN_TESTS()


