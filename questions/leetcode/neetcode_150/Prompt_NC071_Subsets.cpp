// NeetCode 150 NC071: Subsets
// Topic: Backtracking
// Difficulty: Medium
// Source: https://leetcode.com/problems/subsets/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return all subsets of a list of distinct integers.

Examples:
    - Input: [1,2,3] -> 8 subsets
      Explanation: For this input, the correct result is 8 subsets.
    - Input: [] -> [[]]
      Explanation: For this input, the correct result is [[]].

Implement:
    std::vector<std::vector<int>> SolveSubsets(const std::vector<int>& nums);
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
std::vector<std::vector<int>> SolveSubsets(const std::vector<int>& nums) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [1,2,3] -> 8 subsets
    // Explanation: For this input, the correct result is 8 subsets.
    // Case 2: Input: [] -> [[]]
    // Explanation: For this input, the correct result is [[]].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveSubsets({});
    return true;
}

RUN_TESTS()
