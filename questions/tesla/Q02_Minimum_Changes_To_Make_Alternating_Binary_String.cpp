// Run from this file directory:
//   mkdir -p ../../questions_artifacts/tesla && g++ -std=c++17 -I../../include Q02_Minimum_Changes_To_Make_Alternating_Binary_String.cpp -o ../../questions_artifacts/tesla/tesla_q02 && ../../questions_artifacts/tesla/tesla_q02

// Tesla Q02: Minimum Changes To Make Alternating Binary String
/*
Description:
Given a binary string containing only '0' and '1', return the fewest character
flips needed to make adjacent characters alternate.

Only two final patterns are possible:
    010101...
    101010...

Examples:
    "0100" -> 1
        Change the last '0' to '1', producing "0101".

    "10" -> 0
        The string already alternates.

    "1111" -> 2
        Change either positions 0 and 2 to get "0101", or positions 1 and 3 to get "1010".

Edge cases:
    A length-1 string is already alternating.
    You only count character changes, not swaps or deletions.

Task:
Implement this function:
    int MinOperationsToAlternate(const std::string& s);
*/

#include "MathTypes.h"
#include <string>
#include <algorithm>

int MinOperationsToAlternate(const std::string& s) {
    int flipsStartZero = 0;
    int flipsStartOne = 0;

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        char expectedStartZero = (i % 2 == 0) ? '0' : '1';
        char expectedStartOne = (i % 2 == 0) ? '1' : '0';

        if (s[i] != expectedStartZero) {
            ++flipsStartZero;
        }
        if (s[i] != expectedStartOne) {
            ++flipsStartOne;
        }
    }

    return std::min(flipsStartZero, flipsStartOne);
}

bool RunTests() {
    EXPECT_EQ_INT(MinOperationsToAlternate("0100"), 1);
    EXPECT_EQ_INT(MinOperationsToAlternate("10"), 0);
    EXPECT_EQ_INT(MinOperationsToAlternate("1111"), 2);
    EXPECT_EQ_INT(MinOperationsToAlternate("10010100"), 3);
    return true;
}

RUN_TESTS()
