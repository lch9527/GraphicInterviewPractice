// Run from this file directory:
//   mkdir -p "../../questions_artifacts/3D math" && g++ -std=c++17 -I../../include Q14_Reflect_a_Vector_Around_a_Normal.cpp -o "../../questions_artifacts/3D math/3d_math_q14" && "../../questions_artifacts/3D math/3d_math_q14"

// Build: cmake --build build --config Debug --target Q14_Reflect_a_Vector_Around_a_Normal
// Run: .\build\Debug\Q14_Reflect_a_Vector_Around_a_Normal.exe
/*
Question 14: Reflect a Vector Around a Normal

Description:
Given incoming vector I and normalized surface normal N, return reflected vector.

Task:
Implement this function:
    Vec3 Reflect(const Vec3& I, const Vec3& N);

How to run this file:
    g++ -std=c++17 -I../../include Q14_Reflect_a_Vector_Around_a_Normal.cpp -o q14 && ./q14

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec3 Reflect(const Vec3& I, const Vec3& N) {
    // TODO: implement this function.
    return I - (Dot(I,N) * N ) * 2;

}

bool RunTests() {

    EXPECT_VEC3(Reflect({1,-1,0}, {0,1,0}), Vec3{1,1,0});
    EXPECT_VEC3(Reflect({0,-1,0}, {0,1,0}), Vec3{0,1,0});

    return true;
}

RUN_TESTS()


