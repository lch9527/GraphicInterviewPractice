// Run from this file directory:
//   mkdir -p ../../questions_artifacts/tesla && g++ -std=c++17 -I../../include Q08_Valid_Parentheses.cpp -o ../../questions_artifacts/tesla/tesla_q08 && ../../questions_artifacts/tesla/tesla_q08

// Tesla Q08: Valid Parentheses
/*
Description:
Return true when each bracket closes in the correct order and with the matching type.

Task:
Implement this function:
    bool IsValidParentheses(const std::string& s);
*/

#include "MathTypes.h"
#include <string>
#include <vector>

bool Matches(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool IsValidParentheses(const std::string& s) {
    std::vector<char> stack;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push_back(c);
        } else {
            if (stack.empty() || !Matches(stack.back(), c)) return false;
            stack.pop_back();
        }
    }
    return stack.empty();
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

