/*
CoderPad Rendering Question 10: UI Rectangle Intersection and Clipping

Implement rectangle overlap and intersection for UI clipping/scissor logic.
*/

#include "MathTypes.h"
#include <algorithm>
#include <iostream>

struct Rect {
    float xMin = 0.0f;
    float yMin = 0.0f;
    float xMax = 0.0f;
    float yMax = 0.0f;
};

bool AlmostEqualRect(const Rect& a, const Rect& b) {
    return AlmostEqual(a.xMin, b.xMin) && AlmostEqual(a.yMin, b.yMin) &&
           AlmostEqual(a.xMax, b.xMax) && AlmostEqual(a.yMax, b.yMax);
}

bool RectsOverlap(const Rect& a, const Rect& b) {
    // TODO: use strict comparisons so touching edges are not overlap area.
    return a.xMin < b.xMax && a.xMax > b.xMin && a.yMin < b.yMax && a.yMax > b.yMin;
}

Rect IntersectRect(const Rect& a, const Rect& b) {
    // TODO: return an empty {0,0,0,0} rectangle if there is no overlap.
    if (!RectsOverlap(a, b)) return {};
    return {std::max(a.xMin, b.xMin), std::max(a.yMin, b.yMin),
            std::min(a.xMax, b.xMax), std::min(a.yMax, b.yMax)};
}

bool RunTests() {
    Rect a{0,0,10,10};
    Rect b{5,4,12,8};
    Rect c{10,0,20,10};
    EXPECT_TRUE(RectsOverlap(a, b));
    EXPECT_FALSE(RectsOverlap(a, c));
    EXPECT_TRUE(AlmostEqualRect(IntersectRect(a, b), {5,4,10,8}));
    EXPECT_TRUE(AlmostEqualRect(IntersectRect(a, c), {0,0,0,0}));
    return true;
}

int main() {
    bool ok = RunTests();
    std::cout << (ok ? "[PASS] " : "[FAIL] ") << "Q10 UI Rectangle Clipping\n";
    return ok ? 0 : 1;
}

/*
Interview explanation:
Scissor and clipping rectangles are interval intersections in x and y. Edges
that only touch usually produce zero area and are treated as no overlap.
*/
