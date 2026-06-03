// NeetCode 150 NC072: Combination Sum
// Topic: Backtracking
// Difficulty: Medium
// Source: https://leetcode.com/problems/combination-sum/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return combinations where candidates may be reused and sum to target.

Examples:
    - Input: candidates=[2,3,6,7], target=7 -> [[2,2,3],[7]]
      Explanation: For this input, the correct result is [[2,2,3],[7]].
    - Input: [2,3,5], target=8 -> [[2,2,2,2],[2,3,3],[3,5]]
      Explanation: For this input, the correct result is [[2,2,2,2],[2,3,3],[3,5]].

Implement:
    std::vector<std::vector<int>> SolveCombinationSum(const std::vector<int>& candidates, int target);
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
std::vector<std::vector<int>> SolveCombinationSum(const std::vector<int>& candidates, int target) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: candidates=[2,3,6,7], target=7 -> [[2,2,3],[7]]
    // Explanation: For this input, the correct result is [[2,2,3],[7]].
    // Case 2: Input: [2,3,5], target=8 -> [[2,2,2,2],[2,3,3],[3,5]]
    // Explanation: For this input, the correct result is [[2,2,2,2],[2,3,3],[3,5]].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveCombinationSum({}, 0);
    return true;
}

RUN_TESTS()
