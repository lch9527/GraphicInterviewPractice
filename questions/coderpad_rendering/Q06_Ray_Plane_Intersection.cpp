/*
CoderPad Rendering Question 6: Ray-Plane Intersection

Implement ray-plane intersection. This is a CoderPad-focused variation of the
existing ray-plane question.
*/

#include "MathTypes.h"
#include <iostream>

constexpr float LOCAL_EPSILON = 1e-6f;

bool RayPlaneIntersection(const Vec3& rayOrigin, const Vec3& rayDir, const Vec3& planeNormal,
                          const Vec3& pointOnPlane, float& outT) {
    // TODO: solve ray equation P = O + tD against the plane equation.
    float planeD = -DotHelper(planeNormal, pointOnPlane);
    float normalDotRayDir = DotHelper(planeNormal, rayDir);
    if (std::fabs(normalDotRayDir) < LOCAL_EPSILON) return false;
    outT = -(DotHelper(planeNormal, rayOrigin) + planeD) / normalDotRayDir;
    return outT >= 0.0f;
}

bool RunTests() {
    float t = -1.0f;
    EXPECT_TRUE(RayPlaneIntersection({0,0,0}, {0,1,0}, {0,1,0}, {0,5,0}, t));
    EXPECT_NEAR(t, 5.0f);
    EXPECT_FALSE(RayPlaneIntersection({0,0,0}, {1,0,0}, {0,1,0}, {0,5,0}, t));
    EXPECT_FALSE(RayPlaneIntersection({0,0,0}, {0,-1,0}, {0,1,0}, {0,5,0}, t));
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q06 Ray Plane Intersection\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
The dot of the plane normal and ray direction tells whether the ray is parallel.
The solved t value must be non-negative for a forward ray hit.
*/
