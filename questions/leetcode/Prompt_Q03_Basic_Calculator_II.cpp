// LeetCode Q03: Basic Calculator II
// CoderPad-style prompt file. Implement the TODO function, then add or run tests.

/*
Evaluate a string expression containing non-negative integers, spaces, and the
operators '+', '-', '*', and '/'. Division truncates toward zero. No parentheses.

Examples:
    "3+2*2" -> 7
    " 3/2 " -> 1
    " 3+5 / 2 " -> 5

Implement:
    int CalculateBasicExpression(const std::string& expression);
*/

#include "MathTypes.h"
#include <string>

int CalculateBasicExpression(const std::string& expression) {
    // TODO: implement.
    (void)expression;
    return 0;
}

bool RunTests() {
    EXPECT_EQ_INT(CalculateBasicExpression("3+2*2"), 7);
    EXPECT_EQ_INT(CalculateBasicExpression(" 3/2 "), 1);
    EXPECT_EQ_INT(CalculateBasicExpression(" 3+5 / 2 "), 5);
    return true;
}

RUN_TESTS()
