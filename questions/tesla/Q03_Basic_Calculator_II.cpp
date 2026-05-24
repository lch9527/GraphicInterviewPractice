// Tesla Q03: Basic Calculator II
/*
Description:
Evaluate a non-negative integer expression containing '+', '-', '*', '/', and spaces.
Division truncates toward zero.

Task:
Implement this function:
    int CalculateBasicExpression(const std::string& expression);
*/

#include "MathTypes.h"
#include <string>
#include <vector>
#include <cctype>

int CalculateBasicExpression(const std::string& expression) {
    std::vector<int> terms;
    int currentNumber = 0;
    char pendingOperator = '+';

    for (size_t i = 0; i <= expression.size(); ++i) {
        char c = (i < expression.size()) ? expression[i] : '+';
        if (i < expression.size() && std::isspace(static_cast<unsigned char>(c))) {
            continue;
        }

        if (i < expression.size() && std::isdigit(static_cast<unsigned char>(c))) {
            currentNumber = currentNumber * 10 + (c - '0');
            continue;
        }

        if (pendingOperator == '+') {
            terms.push_back(currentNumber);
        } else if (pendingOperator == '-') {
            terms.push_back(-currentNumber);
        } else if (pendingOperator == '*') {
            terms.back() *= currentNumber;
        } else if (pendingOperator == '/') {
            terms.back() /= currentNumber;
        }

        pendingOperator = c;
        currentNumber = 0;
    }

    int result = 0;
    for (int term : terms) result += term;
    return result;
}

bool RunTests() {
    EXPECT_EQ_INT(CalculateBasicExpression("3+2*2"), 7);
    EXPECT_EQ_INT(CalculateBasicExpression(" 3/2 "), 1);
    EXPECT_EQ_INT(CalculateBasicExpression(" 3+5 / 2 "), 5);
    EXPECT_EQ_INT(CalculateBasicExpression("14-3/2"), 13);
    return true;
}

RUN_TESTS()

