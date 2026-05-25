// Run from this file directory:
//   mkdir -p ../questions_artifacts && g++ -std=c++17 -I../include Q34_Make_Billboard_Quad_Face_Camera.cpp -o ../questions_artifacts/q34 && ../questions_artifacts/q34

// Build: cmake --build build --config Debug --target Q34_Make_Billboard_Quad_Face_Camera
// Run: .\build\Debug\Q34_Make_Billboard_Quad_Face_Camera.exe
/*
Question 34: Make Billboard Quad Face Camera

Description:
Given center, size, camera right/up, output quad corners.

Task:
Implement this function:
    void BuildBillboardQuad(const Vec3& center, float width, float height, const Vec3& cameraRight, const Vec3& cameraUp, Vec3 outCorners[4]);

How to run this file:
    g++ -std=c++17 -I../include Q34_Make_Billboard_Quad_Face_Camera.cpp -o q34 && ./q34

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

void BuildBillboardQuad(const Vec3& center, float width, float height, const Vec3& cameraRight, const Vec3& cameraUp, Vec3 outCorners[4]) {

    Vec3 boardnormal = cross(cameraRight, cameraUp) * -1;

    Vec3 toppoint = cameraUp * (height/2);
    Vec3 rightpoit = cameraRight * (width/2);

    outCorners[0] = (toppoint * -1) + (rightpoit * -1) + center;
    outCorners[1] = (toppoint * -1) + (rightpoit) + center;
    outCorners[2] = toppoint + rightpoit + center;
    outCorners[3] = toppoint + (rightpoit * -1) + center; 



    // TODO: implement this function.
    // fill outCorners[0..3]
}

bool RunTests() {

    Vec3 corners[4];
    BuildBillboardQuad({0,0,0}, 2.0f, 4.0f, {1,0,0}, {0,1,0}, corners);
    EXPECT_VEC3(corners[0], Vec3{-1,-2,0});
    EXPECT_VEC3(corners[1], Vec3{1,-2,0});
    EXPECT_VEC3(corners[2], Vec3{1,2,0});
    EXPECT_VEC3(corners[3], Vec3{-1,2,0});

    return true;
}

RUN_TESTS()


