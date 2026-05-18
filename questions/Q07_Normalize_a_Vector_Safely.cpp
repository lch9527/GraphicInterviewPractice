// Run: .\build\Debug\Q07_Normalize_a_Vector_Safely.exe
/*
Question 7: Normalize a Vector Safely

Description:
Return normalized vector. If length is almost zero, return {0,0,0}.

Task:
Implement this function:
    Vec3 NormalizeSafe(const Vec3& v);

How to run this file:
    g++ -std=c++17 -I../include Q07_Normalize_a_Vector_Safely.cpp -o q07 && ./q07

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec3 NormalizeSafe(const Vec3& v) {
    // TODO: implement this function.
    return {};
}

bool RunTests() {

    EXPECT_VEC3(NormalizeSafe({3,0,0}), Vec3{1,0,0});
    EXPECT_VEC3(NormalizeSafe({0,0,0}), Vec3{0,0,0});
    EXPECT_VEC3(NormalizeSafe({0,3,4}), Vec3{0,0.6f,0.8f});

    return true;
}

RUN_TESTS()

