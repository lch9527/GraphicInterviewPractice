// NeetCode 150 NC109: Longest Increasing Subsequence
// Topic: Dynamic Programming
// Difficulty: Medium
// Source: https://leetcode.com/problems/longest-increasing-subsequence/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the length of the longest strictly increasing subsequence.

Examples:
    - Input: [10,9,2,5,3,7,101,18] -> 4
      Explanation: For this input, the correct result is 4.
    - Input: [7,7,7,7,7] -> 1
      Explanation: For this input, the correct result is 1.

Implement:
    int SolveLongestIncreasingSubsequence(const std::vector<int>& nums);
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
int SolveLongestIncreasingSubsequence(const std::vector<int>& nums) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [10,9,2,5,3,7,101,18] -> 4
    // Explanation: For this input, the correct result is 4.
    // Case 2: Input: [7,7,7,7,7] -> 1
    // Explanation: For this input, the correct result is 1.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveLongestIncreasingSubsequence({});
    return true;
}

RUN_TESTS()
