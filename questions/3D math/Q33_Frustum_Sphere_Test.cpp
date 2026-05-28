// Run from this file directory:
//   mkdir -p "../../questions_artifacts/3D math" && g++ -std=c++17 -I../../include Q33_Frustum_Sphere_Test.cpp -o "../../questions_artifacts/3D math/3d_math_q33" && "../../questions_artifacts/3D math/3d_math_q33"

// Build: cmake --build build --config Debug --target Q33_Frustum_Sphere_Test
// Run: .\build\Debug\Q33_Frustum_Sphere_Test.exe
/*
Question 33: Frustum Sphere Test

Description:
Given six planes and sphere, return true if sphere is inside or intersecting frustum.

Task:
Implement this function:
    bool SphereInFrustum(const Plane planes[6], const Vec3& sphereCenter, float sphereRadius);

How to run this file:
    g++ -std=c++17 -I../../include Q33_Frustum_Sphere_Test.cpp -o q33 && ./q33

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

bool SphereInFrustum(const Plane planes[6], const Vec3& sphereCenter, float sphereRadius) {
    // TODO: implement this function.
    for(int i = 0; i < 6; i++){
        float distance = dot(planes[i].normal, sphereCenter) + planes[i].d;
        if(distance < -sphereRadius){
            return false;
        }
    }
    return true;

}

bool RunTests() {

    Plane planes[6] = {
        {{ 1,0,0}, 1}, {{-1,0,0}, 1},
        {{0, 1,0}, 1}, {{0,-1,0}, 1},
        {{0,0, 1}, 1}, {{0,0,-1}, 1}
    };
    EXPECT_TRUE(SphereInFrustum(planes, {0,0,0}, 0.5f));
    EXPECT_TRUE(SphereInFrustum(planes, {1.2f,0,0}, 0.3f));
    EXPECT_FALSE(SphereInFrustum(planes, {2.0f,0,0}, 0.5f));

    return true;
}

RUN_TESTS()


