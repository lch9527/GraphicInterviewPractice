// Run from this file directory:
//   mkdir -p "../../questions_artifacts/3D math" && g++ -std=c++17 -I../../include Q22_Convert_Degrees_to_Radians.cpp -o "../../questions_artifacts/3D math/3d_math_q22" && "../../questions_artifacts/3D math/3d_math_q22"

// Build: cmake --build build --config Debug --target Q22_Convert_Degrees_to_Radians
// Run: .\build\Debug\Q22_Convert_Degrees_to_Radians.exe
/*
Question 22: Convert Degrees to Radians

Description:
Given an angle in degrees, return radians.

Task:
Implement this function:
    float DegreesToRadians(float degrees);

How to run this file:
    g++ -std=c++17 -I../../include Q22_Convert_Degrees_to_Radians.cpp -o q22 && ./q22

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

float DegreesToRadians(float degrees) {
    // TODO: implement this function.
    return degrees * 3.1415926/180;
}

bool RunTests() {

    EXPECT_NEAR(DegreesToRadians(180.0f), PI_F);
    EXPECT_NEAR(DegreesToRadians(90.0f), PI_F / 2.0f);
    EXPECT_NEAR(DegreesToRadians(0.0f), 0.0f);

    return true;
}

RUN_TESTS()


