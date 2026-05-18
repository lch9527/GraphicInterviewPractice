// Build: cmake --build build --config Debug --target Q13_Check_If_Triangle_Faces_Camera
// Run: .\build\Debug\Q13_Check_If_Triangle_Faces_Camera.exe
/*
Question 13: Check If Triangle Faces Camera

Description:
Return true if triangle normal points generally toward camera.

Task:
Implement this function:
    bool IsTriangleFacingCamera(const Vec3& a, const Vec3& b, const Vec3& c, const Vec3& cameraPos);

How to run this file:
    g++ -std=c++17 -I../include Q13_Check_If_Triangle_Faces_Camera.cpp -o q13 && ./q13

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

bool IsTriangleFacingCamera(const Vec3& a, const Vec3& b, const Vec3& c, const Vec3& cameraPos) {
    // TODO: implement this function.
    Vec3 Tnormal = NormalizeHelper(cross(a-b,c-b));

    if(dot(Tnormal,cameraPos) < -0.9){
        return true;
    }
    return false;
}

bool RunTests() {

    EXPECT_TRUE(IsTriangleFacingCamera({0,0,0}, {1,0,0}, {0,1,0}, {0,0,5}));
    EXPECT_FALSE(IsTriangleFacingCamera({0,0,0}, {1,0,0}, {0,1,0}, {0,0,-5}));

    return true;
}

RUN_TESTS()


