/*
CoderPad Rendering Question 8: Ray-AABB Intersection

Implement ray-AABB intersection using the slab method. This is a CoderPad-focused
variation of the existing ray-AABB question.
*/

#include "MathTypes.h"
#include <algorithm>
#include <iostream>
#include <limits>

constexpr float LOCAL_EPSILON = 1e-6f;

bool RayAABBIntersection(const Vec3& rayOrigin, const Vec3& rayDir,
                         const Vec3& boxMin, const Vec3& boxMax, float& outT) {
    // TODO: maintain a near/far interval across x, y, and z slabs.
    float tNear = -std::numeric_limits<float>::infinity();
    float tFar = std::numeric_limits<float>::infinity();
    const float origin[3] = {rayOrigin.x, rayOrigin.y, rayOrigin.z};
    const float dir[3] = {rayDir.x, rayDir.y, rayDir.z};
    const float mn[3] = {boxMin.x, boxMin.y, boxMin.z};
    const float mx[3] = {boxMax.x, boxMax.y, boxMax.z};

    for (int axis = 0; axis < 3; ++axis) {
        if (std::fabs(dir[axis]) < LOCAL_EPSILON) {
            if (origin[axis] < mn[axis] || origin[axis] > mx[axis]) return false;
            continue;
        }
        float t1 = (mn[axis] - origin[axis]) / dir[axis];
        float t2 = (mx[axis] - origin[axis]) / dir[axis];
        if (t1 > t2) std::swap(t1, t2);
        tNear = std::max(tNear, t1);
        tFar = std::min(tFar, t2);
        if (tNear > tFar) return false;
    }

    if (tFar < 0.0f) return false;
    outT = tNear >= 0.0f ? tNear : tFar;
    return true;
}

bool RunTests() {
    float t = -1.0f;
    EXPECT_TRUE(RayAABBIntersection({0,0,0}, {0,0,1}, {-1,-1,5}, {1,1,7}, t));
    EXPECT_NEAR(t, 5.0f);
    EXPECT_FALSE(RayAABBIntersection({0,0,0}, {0,1,0}, {-1,-1,5}, {1,1,7}, t));
    EXPECT_TRUE(RayAABBIntersection({0,0,6}, {0,0,1}, {-1,-1,5}, {1,1,7}, t));
    EXPECT_NEAR(t, 1.0f);
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q08 Ray AABB Intersection\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
Each axis contributes an interval of valid t values. The ray hits only if all
three intervals overlap and the overlap is not entirely behind the origin.
*/
