// Run from this file directory:
//   mkdir -p ../../questions_artifacts/tesla && g++ -std=c++17 -I../../include Q08_Valid_Parentheses.cpp -o ../../questions_artifacts/tesla/tesla_q08 && ../../questions_artifacts/tesla/tesla_q08

// Tesla Q08: Valid Parentheses
/*
Description:
Given a string containing only '(', ')', '[', ']', '{', and '}', return true
when every opening bracket is closed by the same bracket type and in the correct
nested order.

Examples:
    "()" -> true
        One pair, correctly closed.

    "()[]{}" -> true
        Multiple independent valid pairs.

    "(]" -> false
        The opening '(' cannot be closed by ']'.

    "([)]" -> false
        The types match somewhere, but the nesting order is wrong.

    "{[]}" -> true
        Nested brackets close from the inside out.

Edge cases:
    "(" -> false because it is never closed.
    A closing bracket with no earlier matching opener is invalid.

Task:
Implement this function:
    bool IsValidParentheses(const std::string& s);
*/

#include "MathTypes.h"
#include <string>
#include <vector>

bool Matches(char open, char close) {
    // TODO: implement if you want to use this helper.
    (void)open;
    (void)close;
    return false;
}

bool IsValidParentheses(const std::string& s) {
    // TODO: implement.
    (void)s;
    return false;
}

bool RunTests() {
    EXPECT_TRUE(IsValidParentheses("()"));
    EXPECT_TRUE(IsValidParentheses("()[]{}"));
    EXPECT_FALSE(IsValidParentheses("(]"));
    EXPECT_FALSE(IsValidParentheses("([)]"));
    EXPECT_TRUE(IsValidParentheses("{[]}"));
    EXPECT_FALSE(IsValidParentheses("("));
    return true;
}

RUN_TESTS()

