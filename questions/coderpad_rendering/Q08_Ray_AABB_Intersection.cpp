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
    // TODO: track tNear and tFar across x/y/z slabs.
    (void)rayOrigin;
    (void)rayDir;
    (void)boxMin;
    (void)boxMax;
    outT = 0.0f;
    return false;
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
