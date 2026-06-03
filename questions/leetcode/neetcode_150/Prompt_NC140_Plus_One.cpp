// NeetCode 150 NC140: Plus One
// Topic: Math & Geometry
// Difficulty: Easy
// Source: https://leetcode.com/problems/plus-one/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Add one to a non-negative integer represented as an array of digits.

Examples:
    - Input: [1,2,3] -> [1,2,4]
      Explanation: For this input, the correct result is [1,2,4].
    - Input: [9,9] -> [1,0,0]
      Explanation: For this input, the correct result is [1,0,0].

Implement:
    std::vector<int> SolvePlusOne(const std::vector<int>& digits);
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
std::vector<int> SolvePlusOne(const std::vector<int>& digits) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [1,2,3] -> [1,2,4]
    // Explanation: For this input, the correct result is [1,2,4].
    // Case 2: Input: [9,9] -> [1,0,0]
    // Explanation: For this input, the correct result is [1,0,0].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolvePlusOne({});
    return true;
}

RUN_TESTS()
