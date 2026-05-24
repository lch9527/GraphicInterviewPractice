// Tesla Q07: Letter Combinations of a Phone Number
/*
Description:
Return every possible letter combination for a digit string using telephone keypad mapping.

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
    if (index == static_cast<int>(digits.size())) {
        results.push_back(current);
        return;
    }

    const std::string& letters = mapping[digits[index] - '0'];
    for (char letter : letters) {
        current.push_back(letter);
        BuildCombinations(digits, mapping, index + 1, current, results);
        current.pop_back();
    }
}

std::vector<std::string> LetterCombinations(const std::string& digits) {
    if (digits.empty()) return {};

    std::vector<std::string> mapping = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    std::vector<std::string> results;
    std::string current;
    BuildCombinations(digits, mapping, 0, current, results);
    return results;
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

