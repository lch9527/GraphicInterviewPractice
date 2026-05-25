// Run from this file directory:
//   mkdir -p ../questions_artifacts && g++ -std=c++17 -I../include Q07_Normalize_a_Vector_Safely.cpp -o ../questions_artifacts/q07 && ../questions_artifacts/q07

// Build: cmake --build build --config Debug --target Q07_Normalize_a_Vector_Safely
// Run: .\build\Debug\Q07_Normalize_a_Vector_Safely.exe
/*
Question 7: Normalize a Vector Safely

Description:
Return normalized vector. If length is almost zero, return {0,0,0}.

Task:
Implement this function:
    Vec3 NormalizeSafe(const Vec3& v);

How to run this file:


Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec3 NormalizeSafe(const Vec3& v) {
    // TODO: implement this function.
    Vec3 result;
    float length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    if (length > 1e-6f) {
        result.x = v.x / length;
        result.y = v.y / length;
        result.z = v.z / length;
        return result;
    }   
    return {};
}

bool RunTests() {

    EXPECT_VEC3(NormalizeSafe({3,0,0}), Vec3{1,0,0});
    EXPECT_VEC3(NormalizeSafe({0,0,0}), Vec3{0,0,0});
    EXPECT_VEC3(NormalizeSafe({0,3,4}), Vec3{0,0.6f,0.8f});

    return true;
}

RUN_TESTS()


