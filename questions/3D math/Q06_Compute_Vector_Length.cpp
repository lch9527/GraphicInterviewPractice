// Run from this file directory:
//   mkdir -p "../../questions_artifacts/3D math" && g++ -std=c++17 -I../../include Q06_Compute_Vector_Length.cpp -o "../../questions_artifacts/3D math/3d_math_q06" && "../../questions_artifacts/3D math/3d_math_q06"

// Build: cmake --build build --config Debug --target Q06_Compute_Vector_Length
// Run: .\build\Debug\Q06_Compute_Vector_Length.exe
/*
Question 6: Compute Vector Length

Description:
Given a vector, return its magnitude/length.

Task:
Implement this function:
    float Length(const Vec3& v);

How to run this file:
    g++ -std=c++17 -I../../include Q06_Compute_Vector_Length.cpp -o q06 && ./q06

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

float Length(const Vec3& v) {
    // TODO: implement this function.
    float result = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return result;
}

bool RunTests() {

    EXPECT_NEAR(Length({3,4,0}), 5.0f);
    EXPECT_NEAR(Length({0,0,0}), 0.0f);
    EXPECT_NEAR(Length({1,2,2}), 3.0f);

    return true;
}

RUN_TESTS()

