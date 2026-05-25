// Run from this file directory:
//   mkdir -p ../../questions_artifacts/coderpad_rendering && g++ -std=c++17 -I../../include Q08_Ray_AABB_Intersection.cpp -o ../../questions_artifacts/coderpad_rendering/coderpad_q08 && ../../questions_artifacts/coderpad_rendering/coderpad_q08

/*
CoderPad Rendering Question 8: Ray-AABB Intersection

Task:
Implement ray-AABB intersection using the slab method.

Concepts tested:
- axis-aligned bounding boxes
- min/max t intervals
- parallel axis handling
*/

#include "MathTypes.h"
#include <iostream>
#include <limits>

constexpr float LOCAL_EPSILON = 1e-6f;

bool RayAABBIntersection(const Vec3& rayOrigin, const Vec3& rayDir,
                         const Vec3& boxMin, const Vec3& boxMax,
                         float& outT) {
    float totalMin = -std::numeric_limits<float>::infinity();
    float totalMax = std::numeric_limits<float>::infinity();

    if (std::fabs(rayDir.x) < LOCAL_EPSILON) {
        if (rayOrigin.x < boxMin.x || rayOrigin.x > boxMax.x) {
            return false;
        }
        
    } else {
        float tx1 = (boxMin.x - rayOrigin.x) / rayDir.x;
        float tx2 = (boxMax.x - rayOrigin.x) / rayDir.x;
        float txmin = std::min(tx1, tx2);
        float txmax = std::max(tx1, tx2);

        totalMin = std::max(totalMin, txmin);
        totalMax = std::min(totalMax, txmax);
        if (totalMin > totalMax) return false;
    }

    if (std::fabs(rayDir.y) < LOCAL_EPSILON) {
        if (rayOrigin.y < boxMin.y || rayOrigin.y > boxMax.y) {
            return false;
        }
    } else {
        float ty1 = (boxMin.y - rayOrigin.y) / rayDir.y;
        float ty2 = (boxMax.y - rayOrigin.y) / rayDir.y;
        float tymin = std::min(ty1, ty2);
        float tymax = std::max(ty1, ty2);

        totalMin = std::max(totalMin, tymin);
        totalMax = std::min(totalMax, tymax);
        if (totalMin > totalMax) return false;
    }

    if (std::fabs(rayDir.z) < LOCAL_EPSILON) {
        if (rayOrigin.z < boxMin.z || rayOrigin.z > boxMax.z) {
            return false;
        }
    } else {
        float tz1 = (boxMin.z - rayOrigin.z) / rayDir.z;
        float tz2 = (boxMax.z - rayOrigin.z) / rayDir.z;
        float tzmin = std::min(tz1, tz2);
        float tzmax = std::max(tz1, tz2);

        totalMin = std::max(totalMin, tzmin);
        totalMax = std::min(totalMax, tzmax);
        if (totalMin > totalMax) return false;
    }

    if (totalMax < 0.0f) {
        return false;
    }

    outT = std::max(totalMin, 0.0f);
    return true;
}

bool RunTests() {
    float t = -1.0f;
    EXPECT_TRUE(RayAABBIntersection({0,0,0}, {0,0,1}, {-1,-1,5}, {1,1,7}, t));
    EXPECT_NEAR(t, 5.0f);
    EXPECT_FALSE(RayAABBIntersection({0,0,0}, {0,1,0}, {-1,-1,5}, {1,1,7}, t));
    EXPECT_TRUE(RayAABBIntersection({0,0,6}, {0,0,1}, {-1,-1,5}, {1,1,7}, t));
    EXPECT_NEAR(t, 0.0f);
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q08 Ray AABB Intersection\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
The slab method intersects the ray with each axis interval and keeps the common
t range. A hit exists if the near time is before the far time and the box is not
entirely behind the ray.
*/
