// Run from this file directory:
//   mkdir -p ../../questions_artifacts/tesla && g++ -std=c++17 -I../../include Q07_Letter_Combinations_of_a_Phone_Number.cpp -o ../../questions_artifacts/tesla/tesla_q07 && ../../questions_artifacts/tesla/tesla_q07

// Tesla Q07: Letter Combinations of a Phone Number
/*
Description:
Given a string of digits from '2' to '9', return every possible letter
combination the digits could represent on a telephone keypad.

Digit mapping:
    2 -> abc
    3 -> def
    4 -> ghi
    5 -> jkl
    6 -> mno
    7 -> pqrs
    8 -> tuv
    9 -> wxyz

Examples:
    "23" -> {"ad","ae","af","bd","be","bf","cd","ce","cf"}
        Pick one letter from the mapping for '2' and one letter from the mapping for '3'.

    "" -> {}
        No digits means no combinations.

    "7" -> {"p","q","r","s"}

Edge cases:
    The answer can be returned in any order.
    Digits 0 and 1 are not part of this problem's input.

Task:
Implement this function:
    std::vector<std::string> LetterCombinations(const std::string& digits);
*/

#include "MathTypes.h"
#include <string>
#include <vector>
#include <algorithm>

void BuildCombinations(const std::string& digits,
                       const std::vector<std::string>& mapping,
                       int index,
                       std::string& current,
                       std::vector<std::string>& results) {
    // TODO: implement if you choose a backtracking solution.
    (void)digits;
    (void)mapping;
    (void)index;
    (void)current;
    (void)results;
}

std::vector<std::string> LetterCombinations(const std::string& digits) {
    // TODO: implement.
    (void)digits;
    return {};
}

bool SameStrings(std::vector<std::string> a, std::vector<std::string> b) {
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    return a == b;
}

bool RunTests() {
    EXPECT_TRUE(SameStrings(LetterCombinations("23"), {"ad","ae","af","bd","be","bf","cd","ce","cf"}));
    EXPECT_TRUE(SameStrings(LetterCombinations(""), {}));
    EXPECT_TRUE(SameStrings(LetterCombinations("7"), {"p","q","r","s"}));
    return true;
}

RUN_TESTS()

