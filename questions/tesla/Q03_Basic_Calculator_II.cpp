// Run from this file directory:
//   mkdir -p ../../questions_artifacts/tesla && g++ -std=c++17 -I../../include Q03_Basic_Calculator_II.cpp -o ../../questions_artifacts/tesla/tesla_q03 && ../../questions_artifacts/tesla/tesla_q03

// Tesla Q03: Basic Calculator II
/*
Description:
Evaluate a string expression containing non-negative integers, spaces, and the
operators '+', '-', '*', and '/'.

Rules:
    Multiplication and division happen before addition and subtraction.
    Division truncates toward zero.
    The input expression does not contain parentheses.
    Spaces should be ignored.

Examples:
    "3+2*2" -> 7
        Multiplication happens first: 3 + 4.

    " 3/2 " -> 1
        Integer division truncates 1.5 toward zero.

    " 3+5 / 2 " -> 5
        5 / 2 becomes 2, so the result is 3 + 2.

Edge cases:
    Multi-digit numbers must be parsed as a full number, not one digit at a time.
    A trailing number still needs to be applied after the loop reaches the end.

Task:
Implement this function:
    int CalculateBasicExpression(const std::string& expression);
*/

#include "MathTypes.h"
#include <string>
#include <vector>
#include <cctype>

int CalculateBasicExpression(const std::string& expression) {
    // TODO: implement.
    std::vector<int> terms;
      int currentNumber = 0;
      char pendingOperator = '+';

      for (int i = 0; i <= static_cast<int>(expression.size()); ++i) {
          char c = (i < static_cast<int>(expression.size())) ? expression[i] : '+';

          if (i < static_cast<int>(expression.size()) &&
              std::isspace(static_cast<unsigned char>(c))) {
              continue;
          }

          if (i < static_cast<int>(expression.size()) &&
              std::isdigit(static_cast<unsigned char>(c))) {
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
      for (int term : terms) {
          result += term;
      }

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

