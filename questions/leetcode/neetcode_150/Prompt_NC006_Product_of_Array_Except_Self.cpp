// NeetCode 150 NC006: Product of Array Except Self
// Topic: Arrays & Hashing
// Difficulty: Medium
// Source: https://leetcode.com/problems/product-of-array-except-self/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    For each position, return the product of all other values without using division.

Examples:
    - Input: [1,2,3,4] -> [24,12,8,6]
      Explanation: For this input, the correct result is [24,12,8,6].
    - Input: [-1,1,0,-3,3] -> [0,0,9,0,0]
      Explanation: For this input, the correct result is [0,0,9,0,0].

Implement:
    std::vector<int> SolveProductExceptSelf(const std::vector<int>& nums);
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
std::vector<int> SolveProductExceptSelf(const std::vector<int>& nums) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [1,2,3,4] -> [24,12,8,6]
    // Explanation: For this input, the correct result is [24,12,8,6].
    // Case 2: Input: [-1,1,0,-3,3] -> [0,0,9,0,0]
    // Explanation: For this input, the correct result is [0,0,9,0,0].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveProductExceptSelf({});
    return true;
}

RUN_TESTS()
