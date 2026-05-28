// Run from this file directory:
//   mkdir -p "../../questions_artifacts/3D math" && g++ -std=c++17 -I../../include Q24_Implement_LookAt_View_Matrix.cpp -o "../../questions_artifacts/3D math/3d_math_q24" && "../../questions_artifacts/3D math/3d_math_q24"

// Build: cmake --build build --config Debug --target Q24_Implement_LookAt_View_Matrix
// Run: .\build\Debug\Q24_Implement_LookAt_View_Matrix.exe
/*
Question 24: Implement LookAt View Matrix

Description:
Return a view matrix for right-handed camera looking from eye to target. Column-major, column-vector style.

Task:
Implement this function:
    Mat4 LookAt(const Vec3& eye, const Vec3& target, const Vec3& worldUp);

How to run this file:
    g++ -std=c++17 -I../../include Q24_Implement_LookAt_View_Matrix.cpp -o q24 && ./q24

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Mat4 LookAt(const Vec3& eye, const Vec3& target, const Vec3& worldUp) {
    // TODO: implement this function.
    Vec3 forward = NormalizeHelper(target - eye);
    Vec3 right = NormalizeHelper(Cross(forward, worldUp));
    Vec3 up = Cross(right, forward);

    Mat4 result = Identity4();

    result.m[0][0] = right.x;
    result.m[0][1] = up.x;
    result.m[0][2] = -forward.x;

    result.m[1][0] = right.y;
    result.m[1][1] = up.y;
    result.m[1][2] = -forward.y;

    result.m[2][0] = right.z;
    result.m[2][1] = up.z;
    result.m[2][2] = -forward.z;

    result.m[3][0] = -Dot(right, eye);
    result.m[3][1] = -Dot(up, eye);
    result.m[3][2] = Dot(forward, eye);

    return result;
}

bool RunTests() {

    Mat4 v = LookAt({0,0,5}, {0,0,0}, {0,1,0});
    Vec4 worldOrigin{0,0,0,1};
    Vec4 viewOrigin = Mul(v, worldOrigin);
    EXPECT_NEAR(viewOrigin.x, 0.0f);
    EXPECT_NEAR(viewOrigin.y, 0.0f);
    EXPECT_NEAR(viewOrigin.z, -5.0f);
    EXPECT_NEAR(viewOrigin.w, 1.0f);

    return true;
}

RUN_TESTS()
