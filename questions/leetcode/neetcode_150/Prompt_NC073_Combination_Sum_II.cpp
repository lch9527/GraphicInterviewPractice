// NeetCode 150 NC073: Combination Sum II
// Topic: Backtracking
// Difficulty: Medium
// Source: https://leetcode.com/problems/combination-sum-ii/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return unique combinations that sum to target, using each candidate at most once.

Examples:
    - Input: candidates=[10,1,2,7,6,1,5], target=8 -> [[1,1,6],[1,2,5],[1,7],[2,6]]
      Explanation: For this input, the correct result is [[1,1,6],[1,2,5],[1,7],[2,6]].
    - Input: [2,5,2,1,2], target=5 -> [[1,2,2],[5]]
      Explanation: For this input, the correct result is [[1,2,2],[5]].

Implement:
    std::vector<std::vector<int>> SolveCombinationSumII(std::vector<int> candidates, int target);
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
std::vector<std::vector<int>> SolveCombinationSumII(std::vector<int> candidates, int target) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: candidates=[10,1,2,7,6,1,5], target=8 -> [[1,1,6],[1,2,5],[1,7],[2,6]]
    // Explanation: For this input, the correct result is [[1,1,6],[1,2,5],[1,7],[2,6]].
    // Case 2: Input: [2,5,2,1,2], target=5 -> [[1,2,2],[5]]
    // Explanation: For this input, the correct result is [[1,2,2],[5]].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveCombinationSumII({}, 0);
    return true;
}

RUN_TESTS()
