// Run from this file directory:
//   mkdir -p ../questions_artifacts && g++ -std=c++17 -I../include Q09_Check_If_Two_Vectors_Point_Same_Direction.cpp -o ../questions_artifacts/q09 && ../questions_artifacts/q09

// Build: cmake --build build --config Debug --target Q09_Check_If_Two_Vectors_Point_Same_Direction
// Run: .\build\Debug\Q09_Check_If_Two_Vectors_Point_Same_Direction.exe
/*
Question 9: Check If Two Vectors Point Same Direction

Description:
Return true if two vectors point generally in the same direction.

Task:
Implement this function:
    bool SameDirection(const Vec3& a, const Vec3& b);

How to run this file:
    g++ -std=c++17 -I../include Q09_Check_If_Two_Vectors_Point_Same_Direction.cpp -o q09 && ./q09

Notes:
- Edit only the TODO function unless you want to add your own tests.
- The tests are at the bottom of this file.
*/

#include "MathTypes.h"

bool SameDirection(const Vec3& a, const Vec3& b) {
    // TODO: implement this function.
    Vec3 newA = NormalizeHelper(a);
    Vec3 newB = NormalizeHelper(b);
    if (Dot(newA, newB) > 0.9) {
        return true;
    }
    return false;
}

bool RunTests() {

    EXPECT_TRUE(SameDirection({1,0,0}, {5,0,0}));
    EXPECT_FALSE(SameDirection({1,0,0}, {-5,0,0}));
    EXPECT_TRUE(SameDirection({1,1,0}, {2,2,0}));

    return true;
}

RUN_TESTS()


