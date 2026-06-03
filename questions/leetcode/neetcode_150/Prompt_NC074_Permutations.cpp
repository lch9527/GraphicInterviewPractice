// NeetCode 150 NC074: Permutations
// Topic: Backtracking
// Difficulty: Medium
// Source: https://leetcode.com/problems/permutations/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return all permutations of a list of distinct integers.

Examples:
    - Input: [1,2,3] -> 6 permutations
      Explanation: For this input, the correct result is 6 permutations.
    - Input: [0,1] -> [[0,1],[1,0]]
      Explanation: For this input, the correct result is [[0,1],[1,0]].

Implement:
    std::vector<std::vector<int>> SolvePermutations(const std::vector<int>& nums);
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
std::vector<std::vector<int>> SolvePermutations(const std::vector<int>& nums) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [1,2,3] -> 6 permutations
    // Explanation: For this input, the correct result is 6 permutations.
    // Case 2: Input: [0,1] -> [[0,1],[1,0]]
    // Explanation: For this input, the correct result is [[0,1],[1,0]].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolvePermutations({});
    return true;
}

RUN_TESTS()
