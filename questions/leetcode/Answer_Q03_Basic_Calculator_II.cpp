// LeetCode Q03: Basic Calculator II - Answer

#include "MathTypes.h"
#include <cctype>
#include <string>
#include <vector>

int CalculateBasicExpression(const std::string& expression) {
    std::vector<int> terms;
    int currentNumber = 0;
    char pendingOperator = '+';

    for (int i = 0; i <= static_cast<int>(expression.size()); ++i) {
        char c = (i < static_cast<int>(expression.size())) ? expression[i] : '+';
        if (i < static_cast<int>(expression.size()) && std::isspace(static_cast<unsigned char>(c))) {
            continue;
        }
        if (i < static_cast<int>(expression.size()) && std::isdigit(static_cast<unsigned char>(c))) {
            currentNumber = currentNumber * 10 + (c - '0');
            continue;
        }

        if (pendingOperator == '+') terms.push_back(currentNumber);
        else if (pendingOperator == '-') terms.push_back(-currentNumber);
        else if (pendingOperator == '*') terms.back() *= currentNumber;
        else if (pendingOperator == '/') terms.back() /= currentNumber;

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
    EXPECT_EQ_INT(CalculateBasicExpression("0"), 0);
    EXPECT_EQ_INT(CalculateBasicExpression("42"), 42);
    EXPECT_EQ_INT(CalculateBasicExpression("1-1+1"), 1);
    EXPECT_EQ_INT(CalculateBasicExpression("2*3+4"), 10);
    EXPECT_EQ_INT(CalculateBasicExpression("2+3*4-5/2"), 12);
    EXPECT_EQ_INT(CalculateBasicExpression("100/3/2"), 16);
    return true;
}

RUN_TESTS()
