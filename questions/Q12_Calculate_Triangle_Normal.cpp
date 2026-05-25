// Run from this file directory:
//   mkdir -p ../questions_artifacts && g++ -std=c++17 -I../include Q12_Calculate_Triangle_Normal.cpp -o ../questions_artifacts/q12 && ../questions_artifacts/q12

// Build: cmake --build build --config Debug --target Q12_Calculate_Triangle_Normal
// Run: .\build\Debug\Q12_Calculate_Triangle_Normal.exe
/*
Question 12: Calculate Triangle Normal

Description:
Given triangle vertices a,b,c, return normalized triangle normal.

Task:
Implement this function:
    Vec3 CalculateTriangleNormal(const Vec3& a, const Vec3& b, const Vec3& c);

How to run this file:
    g++ -std=c++17 -I../include Q12_Calculate_Triangle_Normal.cpp -o q12 && ./q12


Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec3 CalculateTriangleNormal(const Vec3& a, const Vec3& b, const Vec3& c) {
    // TODO: implement this function.
    Vec3 v1 = a-b;
    Vec3 v2 = c-b;

    Vec3 normal = NormalizeHelper(cross(v2 ,v1));


    return normal;
}

bool RunTests() {

    EXPECT_VEC3(CalculateTriangleNormal({0,0,0}, {1,0,0}, {0,1,0}), Vec3{0,0,1});
    EXPECT_VEC3(CalculateTriangleNormal({0,0,0}, {0,1,0}, {1,0,0}), Vec3{0,0,-1});

    return true;
}

RUN_TESTS()


