// Run: .\build\Debug\Q28_Ray-AABB_Intersection.exe
/*
Question 28: Ray-AABB Intersection

Description:
Use slab method to test ray against axis-aligned box and output nearest positive t.

Task:
Implement this function:
    bool RayAABBIntersection(const Vec3& rayOrigin, const Vec3& rayDir, const Vec3& boxMin, const Vec3& boxMax, float& outT);

How to run this file:
    g++ -std=c++17 -I../include Q28_Ray-AABB_Intersection.cpp -o q28 && ./q28

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

bool RayAABBIntersection(const Vec3& rayOrigin, const Vec3& rayDir, const Vec3& boxMin, const Vec3& boxMax, float& outT) {
    // TODO: implement this function.
    outT = 0.0f; return false;
}

bool RunTests() {

    float t = 0.0f;
    EXPECT_TRUE(RayAABBIntersection({0,0,0}, {0,0,1}, {-1,-1,5}, {1,1,7}, t));
    EXPECT_NEAR(t, 5.0f);
    EXPECT_FALSE(RayAABBIntersection({0,0,0}, {0,1,0}, {-1,-1,5}, {1,1,7}, t));
    EXPECT_TRUE(RayAABBIntersection({0,0,6}, {0,0,1}, {-1,-1,5}, {1,1,7}, t));
    EXPECT_NEAR(t, 0.0f);

    return true;
}

RUN_TESTS()

