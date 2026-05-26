// Run from this file directory:
//   mkdir -p ../../questions_artifacts/tesla && g++ -std=c++17 -I../../include Q01_Longest_Substring_Without_Repeating_Characters.cpp -o ../../questions_artifacts/tesla/tesla_q01 && ../../questions_artifacts/tesla/tesla_q01

// Tesla Q01: Longest Substring Without Repeating Characters
/*
Description:
Return the length of the longest contiguous substring that contains no repeated characters.

Task:
Implement this function:
    int LengthOfLongestSubstring(const std::string& s);
*/

#include "MathTypes.h"
#include <string>
#include <vector>
#include <algorithm>

int LengthOfLongestSubstring(const std::string& s) {
    std::vector<int> lastSeen(256, -1);
    int best = 0;
    int left = 0;

    for (int right = 0; right < static_cast<int>(s.size()); ++right) {
        unsigned char c = static_cast<unsigned char>(s[right]);
        if (lastSeen[c] >= left) {
            left = lastSeen[c] + 1;
        }
        lastSeen[c] = right;
        best = std::max(best, right - left + 1);
    }

    return best;
}

bool RunTests() {
    EXPECT_EQ_INT(LengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ_INT(LengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ_INT(LengthOfLongestSubstring("pwwkew"), 3);
    EXPECT_EQ_INT(LengthOfLongestSubstring(""), 0);
    EXPECT_EQ_INT(LengthOfLongestSubstring("dvdf"), 3);
    return true;
}

RUN_TESTS()

