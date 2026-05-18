// Build: cmake --build build --config Debug --target Q15_Project_One_Vector_Onto_Another
// Run: .\build\Debug\Q15_Project_One_Vector_Onto_Another.exe
/*
Question 15: Project One Vector Onto Another

Description:
Return projection of vector a onto vector b.

Task:
Implement this function:
    Vec3 ProjectVector(const Vec3& a, const Vec3& b);

How to run this file:
    g++ -std=c++17 -I../include Q15_Project_One_Vector_Onto_Another.cpp -o q15 && ./q15

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

Vec3 ProjectVector(const Vec3& a, const Vec3& b) {
    // TODO: implement this function.
    return Dot(a,NormalizeHelper(b)) * NormalizeHelper(b);
}

bool RunTests() {

    EXPECT_VEC3(ProjectVector({3,4,0}, {1,0,0}), Vec3{3,0,0});
    EXPECT_VEC3(ProjectVector({3,4,0}, {0,2,0}), Vec3{0,4,0});
    EXPECT_VEC3(ProjectVector({1,2,3}, {0,0,0}), Vec3{0,0,0});

    return true;
}

RUN_TESTS()


