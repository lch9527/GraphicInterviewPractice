// LeetCode Q02: Minimum Changes To Make Alternating Binary String - Answer

#include "MathTypes.h"
#include <algorithm>
#include <string>

int MinOperationsToAlternate(const std::string& s) {
    int startZero = 0;
    int startOne = 0;

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        char expectedZero = (i % 2 == 0) ? '0' : '1';
        char expectedOne = (i % 2 == 0) ? '1' : '0';
        if (s[i] != expectedZero) ++startZero;
        if (s[i] != expectedOne) ++startOne;
    }

    return std::min(startZero, startOne);
}

bool RunTests() {
    EXPECT_EQ_INT(MinOperationsToAlternate("0100"), 1);
    EXPECT_EQ_INT(MinOperationsToAlternate("10"), 0);
    EXPECT_EQ_INT(MinOperationsToAlternate("1111"), 2);
    EXPECT_EQ_INT(MinOperationsToAlternate("10010100"), 3);
    EXPECT_EQ_INT(MinOperationsToAlternate("0"), 0);
    EXPECT_EQ_INT(MinOperationsToAlternate("1"), 0);
    EXPECT_EQ_INT(MinOperationsToAlternate("101010"), 0);
    EXPECT_EQ_INT(MinOperationsToAlternate("0000"), 2);
    EXPECT_EQ_INT(MinOperationsToAlternate("010101001"), 2);
    return true;
}

RUN_TESTS()
