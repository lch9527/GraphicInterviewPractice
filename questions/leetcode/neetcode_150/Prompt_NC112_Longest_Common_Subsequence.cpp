// NeetCode 150 NC112: Longest Common Subsequence
// Topic: Dynamic Programming
// Difficulty: Medium
// Source: https://leetcode.com/problems/longest-common-subsequence/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the length of the longest subsequence common to two strings.

Examples:
    - Input: text1="abcde", text2="ace" -> 3
      Explanation: For this input, the correct result is 3.
    - Input: "abc", "def" -> 0
      Explanation: For this input, the correct result is 0.

Implement:
    int SolveLongestCommonSubsequence(const std::string& text1, const std::string& text2);
*/

#include "MathTypes.h"
#include <algorithm>
#include <cstdint>
#include <deque>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct ListNode { int val; ListNode* next; explicit ListNode(int x = 0, ListNode* n = nullptr) : val(x), next(n) {} };
struct TreeNode { int val; TreeNode* left; TreeNode* right; explicit TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) : val(x), left(l), right(r) {} };
struct GraphNode { int val; std::vector<GraphNode*> neighbors; explicit GraphNode(int x = 0) : val(x) {} };
struct RandomNode { int val; RandomNode* next; RandomNode* random; explicit RandomNode(int x = 0) : val(x), next(nullptr), random(nullptr) {} };
int SolveLongestCommonSubsequence(const std::string& text1, const std::string& text2) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: text1="abcde", text2="ace" -> 3
    // Explanation: For this input, the correct result is 3.
    // Case 2: Input: "abc", "def" -> 0
    // Explanation: For this input, the correct result is 0.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveLongestCommonSubsequence("", "");
    return true;
}

RUN_TESTS()
