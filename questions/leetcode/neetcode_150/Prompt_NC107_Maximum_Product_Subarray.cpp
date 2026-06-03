// NeetCode 150 NC107: Maximum Product Subarray
// Topic: Dynamic Programming
// Difficulty: Medium
// Source: https://leetcode.com/problems/maximum-product-subarray/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the maximum product of a contiguous non-empty subarray.

Examples:
    - Input: [2,3,-2,4] -> 6
      Explanation: For this input, the correct result is 6.
    - Input: [-2,0,-1] -> 0
      Explanation: For this input, the correct result is 0.

Implement:
    int SolveMaximumProductSubarray(const std::vector<int>& nums);
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
int SolveMaximumProductSubarray(const std::vector<int>& nums) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [2,3,-2,4] -> 6
    // Explanation: For this input, the correct result is 6.
    // Case 2: Input: [-2,0,-1] -> 0
    // Explanation: For this input, the correct result is 0.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveMaximumProductSubarray({});
    return true;
}

RUN_TESTS()
