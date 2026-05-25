/*
CoderPad Rendering Question 10: UI Rectangle Intersection and Clipping

Task:
Implement rectangle overlap and intersection for UI clipping/scissor logic.

Concepts tested:
- 2D UI math
- clipping
- scissor rectangles
- min/max edge cases
*/

#include "MathTypes.h"
#include <iostream>

struct Rect {
    float xMin = 0.0f;
    float yMin = 0.0f;
    float xMax = 0.0f;
    float yMax = 0.0f;
};

bool RectsOverlap(const Rect& a, const Rect& b) {
    // TODO: return true only when the rectangles have positive-area overlap.
    (void)a;
    (void)b;
    return false;
}

Rect IntersectRect(const Rect& a, const Rect& b) {
    // TODO: return the overlapped rectangle, or an empty rectangle if no overlap exists.
    (void)a;
    (void)b;
    return {};
}

bool RectNear(const Rect& a, const Rect& b) {
    return AlmostEqual(a.xMin, b.xMin) && AlmostEqual(a.yMin, b.yMin) &&
           AlmostEqual(a.xMax, b.xMax) && AlmostEqual(a.yMax, b.yMax);
}

#define EXPECT_RECT(actual, expected) do { if (!RectNear((actual), (expected))) { \
    std::cerr << "FAILED: rectangle mismatch at line " << __LINE__ << "\n"; return false; } } while(0)

bool RunTests() {
    Rect a{0,0,10,10};
    Rect b{5,5,15,20};
    Rect c{10,10,20,20};

    Rect expectedOverlap{5,5,10,10};
    Rect expectedEmpty{0,0,0,0};

    EXPECT_TRUE(RectsOverlap(a, b));
    EXPECT_FALSE(RectsOverlap(a, c));
    EXPECT_RECT(IntersectRect(a, b), expectedOverlap);
    EXPECT_RECT(IntersectRect(a, c), expectedEmpty);
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q10 UI Rectangle Clipping\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
UI clipping usually keeps the maximum of the minimum edges and the minimum of
the maximum edges. Touching edges are not positive-area overlap.
*/
