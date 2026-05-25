// Run from this file directory:
//   mkdir -p ../../questions_artifacts/tesla && g++ -std=c++17 -I../../include Q02_Minimum_Changes_To_Make_Alternating_Binary_String.cpp -o ../../questions_artifacts/tesla/tesla_q02 && ../../questions_artifacts/tesla/tesla_q02

// Tesla Q02: Minimum Changes To Make Alternating Binary String
/*
Description:
Given a binary string, return the fewest character flips needed to make it alternate.

Task:
Implement this function:
    int MinOperationsToAlternate(const std::string& s);
*/

#include "MathTypes.h"
#include <string>
#include <algorithm>

int MinOperationsToAlternate(const std::string& s) {
    int flipsStartingWithZero = 0;
    int flipsStartingWithOne = 0;

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        char expectedZeroPattern = (i % 2 == 0) ? '0' : '1';
        char expectedOnePattern = (i % 2 == 0) ? '1' : '0';
        if (s[i] != expectedZeroPattern) ++flipsStartingWithZero;
        if (s[i] != expectedOnePattern) ++flipsStartingWithOne;
    }

    return std::min(flipsStartingWithZero, flipsStartingWithOne);
}

bool RunTests() {
    EXPECT_EQ_INT(MinOperationsToAlternate("0100"), 1);
    EXPECT_EQ_INT(MinOperationsToAlternate("10"), 0);
    EXPECT_EQ_INT(MinOperationsToAlternate("1111"), 2);
    EXPECT_EQ_INT(MinOperationsToAlternate("10010100"), 3);
    return true;
}

RUN_TESTS()

