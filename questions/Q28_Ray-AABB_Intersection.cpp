// Run from this file directory:
//   mkdir -p ../questions_artifacts && g++ -std=c++17 -I../include Q28_Ray-AABB_Intersection.cpp -o ../questions_artifacts/q28 && ../questions_artifacts/q28

// Build: cmake --build build --config Debug --target Q28_Ray-AABB_Intersection
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
    const float inf = 1e30f;
    const float eps = 1e-8f;

    float tMin = -inf;
    float tMax = inf;

    // X slab
    if (fabsf(rayDir.x) < eps) {
        if (rayOrigin.x < boxMin.x || rayOrigin.x > boxMax.x) {
            outT = 0.0f;
            return false;
        }
    } else {
        float tx1 = (boxMin.x - rayOrigin.x) / rayDir.x;
        float tx2 = (boxMax.x - rayOrigin.x) / rayDir.x;
        if (tx1 > tx2) { float tmp = tx1; tx1 = tx2; tx2 = tmp; }
        tMin = (tMin > tx1) ? tMin : tx1;
        tMax = (tMax < tx2) ? tMax : tx2;
    }

    // Y slab
    if (fabsf(rayDir.y) < eps) {
        if (rayOrigin.y < boxMin.y || rayOrigin.y > boxMax.y) {
            outT = 0.0f;
            return false;
        }
    } else {
        float ty1 = (boxMin.y - rayOrigin.y) / rayDir.y;
        float ty2 = (boxMax.y - rayOrigin.y) / rayDir.y;
        if (ty1 > ty2) { float tmp = ty1; ty1 = ty2; ty2 = tmp; }
        tMin = (tMin > ty1) ? tMin : ty1;
        tMax = (tMax < ty2) ? tMax : ty2;
    }

    // Z slab
    if (fabsf(rayDir.z) < eps) {
        if (rayOrigin.z < boxMin.z || rayOrigin.z > boxMax.z) {
            outT = 0.0f;
            return false;
        }
    } else {
        float tz1 = (boxMin.z - rayOrigin.z) / rayDir.z;
        float tz2 = (boxMax.z - rayOrigin.z) / rayDir.z;
        if (tz1 > tz2) { float tmp = tz1; tz1 = tz2; tz2 = tmp; }
        tMin = (tMin > tz1) ? tMin : tz1;
        tMax = (tMax < tz2) ? tMax : tz2;
    }

    if (tMax < tMin || tMax < 0.0f) {
        outT = 0.0f;
        return false;
    }

    outT = (tMin > 0.0f) ? tMin : 0.0f;
    return true;
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


