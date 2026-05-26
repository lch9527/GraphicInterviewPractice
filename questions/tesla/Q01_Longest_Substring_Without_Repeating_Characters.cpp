// Run from this file directory:
//   mkdir -p ../../questions_artifacts/tesla && g++ -std=c++17 -I../../include Q01_Longest_Substring_Without_Repeating_Characters.cpp -o ../../questions_artifacts/tesla/tesla_q01 && ../../questions_artifacts/tesla/tesla_q01

// Tesla Q01: Longest Substring Without Repeating Characters
/*
Description:
A substring is a contiguous block of characters from the original string.
Return the length of the longest substring that contains no repeated characters.

Examples:
    "abccabcbb" -> 3
        The answer is "abc". When a repeated 'a' appears, the valid window must move forward.

    "bbbbb" -> 1
        Every valid substring can contain only one 'b'.

    "pwwkew" -> 3
        The answer is "wke". "pwke" is not valid because it is not contiguous.

Edge cases:
    "" -> 0
    A string with all unique characters returns s.size().

Task:
Implement this function:
    int LengthOfLongestSubstring(const std::string& s);
*/

#include "MathTypes.h"
#include <string>
#include <vector>
#include <algorithm>

int LengthOfLongestSubstring(const std::string& s) {
    std::unordered_set <char> cset;
    int lindex = 0, ans = 0;
    for(int i = 0; i < s.length(); ++i){
        while(cset.find(s[i]) != cset.end()){
            //cset.insert(s[i]);
            cset.erase(s[lindex]);
            lindex++;
        }
        cset.insert(s[i]);
        ans = std::max(ans,static_cast<int>(cset.size())); 

    }
    return ans;

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
