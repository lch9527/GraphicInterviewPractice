// NeetCode 150 NC085: Pacific Atlantic Water Flow
// Topic: Graphs
// Difficulty: Medium
// Source: https://leetcode.com/problems/pacific-atlantic-water-flow/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return cells where water can flow to both the Pacific and Atlantic edges.

Examples:
    - Input: standard 5x5 height grid -> cells including [0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]
      Explanation: For this input, the correct result is cells including [0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0].
    - Input: [[1]] -> [[0,0]]
      Explanation: For this input, the correct result is [[0,0]].

Implement:
    std::vector<std::vector<int>> SolvePacificAtlanticWaterFlow(const std::vector<std::vector<int>>& heights);
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
std::vector<std::vector<int>> SolvePacificAtlanticWaterFlow(const std::vector<std::vector<int>>& heights) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: standard 5x5 height grid -> cells including [0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]
    // Explanation: For this input, the correct result is cells including [0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0].
    // Case 2: Input: [[1]] -> [[0,0]]
    // Explanation: For this input, the correct result is [[0,0]].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolvePacificAtlanticWaterFlow({});
    return true;
}

RUN_TESTS()
