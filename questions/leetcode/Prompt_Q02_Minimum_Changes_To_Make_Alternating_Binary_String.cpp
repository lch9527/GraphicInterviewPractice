// LeetCode Q02: Minimum Changes To Make Alternating Binary String
// CoderPad-style prompt file. Implement the TODO function, then add or run tests.

/*
Given a binary string s, return the minimum number of character changes needed
so adjacent characters alternate. Only changes are allowed, not swaps/deletions.

Examples:
    "0100" -> 1
    "10" -> 0
    "1111" -> 2

Implement:
    int MinOperationsToAlternate(const std::string& s);
*/

#include "MathTypes.h"
#include <string>

int MinOperationsToAlternate(const std::string& s) {
    // TODO: implement.
    (void)s;
    return 0;
}

bool RunTests() {
    EXPECT_EQ_INT(MinOperationsToAlternate("0100"), 1);
    EXPECT_EQ_INT(MinOperationsToAlternate("10"), 0);
    EXPECT_EQ_INT(MinOperationsToAlternate("1111"), 2);
    return true;
}

RUN_TESTS()
