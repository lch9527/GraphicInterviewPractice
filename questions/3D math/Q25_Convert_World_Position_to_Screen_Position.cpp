// Run from this file directory:
//   mkdir -p "../../questions_artifacts/3D math" && g++ -std=c++17 -I../../include Q25_Convert_World_Position_to_Screen_Position.cpp -o "../../questions_artifacts/3D math/3d_math_q25" && "../../questions_artifacts/3D math/3d_math_q25"

// Build: cmake --build build --config Debug --target Q25_Convert_World_Position_to_Screen_Position
// Run: .\build\Debug\Q25_Convert_World_Position_to_Screen_Position.exe
/*
Question 25: Convert World Position to Screen Position

Description:
Given world position and viewProjection, return pixel coordinate. Assume NDC y-up but screen y-down.

Task:
Implement this function:
    Vec2 WorldToScreen(const Vec3& worldPos, const Mat4& viewProjection, float screenWidth, float screenHeight);

How to run this file:
    g++ -std=c++17 -I../../include Q25_Convert_World_Position_to_Screen_Position.cpp -o q25 && ./q25

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec2 WorldToScreen(const Vec3& worldPos, const Mat4& viewProjection, float screenWidth, float screenHeight) {
    // TODO: implement this function.
     Vec4 clip = Mul(viewProjection, Vec4{worldPos.x, worldPos.y, worldPos.z, 1.0f});
        if (std::fabs(clip.w) < EPSILON) {
            return {};
        }
    
        float ndcX = clip.x / clip.w;
        float ndcY = clip.y / clip.w;
    
        return {
            (ndcX + 1.0f) * 0.5f * screenWidth,
            (1.0f - ndcY) * 0.5f * screenHeight
        };

    return {};
}

bool RunTests() {

    Mat4 identity = Identity4();
    EXPECT_VEC2(WorldToScreen({0,0,0}, identity, 800, 600), Vec2{400,300});
    EXPECT_VEC2(WorldToScreen({1,1,0}, identity, 800, 600), Vec2{800,0});
    EXPECT_VEC2(WorldToScreen({-1,-1,0}, identity, 800, 600), Vec2{0,600});

    return true;
}

RUN_TESTS()


