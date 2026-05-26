// Run from this file directory:
//   mkdir -p ../questions_artifacts && g++ -std=c++17 -I../include Q30_Vector_Lerp.cpp -o ../questions_artifacts/q30 && ../questions_artifacts/q30

// Build: cmake --build build --config Debug --target Q30_Vector_Lerp
// Run: .\build\Debug\Q30_Vector_Lerp.exe
/*
Question 30: Vector Lerp

Description:
Implement vector linear interpolation.

Task:
Implement this function:
    Vec3 LerpVec3(const Vec3& a, const Vec3& b, float t);

How to run this file:
    g++ -std=c++17 -I../include Q30_Vector_Lerp.cpp -o q30 && ./q30

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec3 LerpVec3(const Vec3& a, const Vec3& b, float t) {
    // TODO: implement this function.
    return a + (b - a) * t;
}

bool RunTests() {

    EXPECT_VEC3(LerpVec3({0,0,0}, {10,0,0}, 0.25f), Vec3{2.5f,0,0});
    EXPECT_VEC3(LerpVec3({1,2,3}, {3,4,5}, 0.5f), Vec3{2,3,4});

    return true;
}

RUN_TESTS()


