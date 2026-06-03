// NeetCode 150 NC090: Number of Connected Components in an Undirected Graph
// Topic: Graphs
// Difficulty: Medium
// Source: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Count connected components in an undirected graph with n nodes.

Examples:
    - Input: n=5, edges=[[0,1],[1,2],[3,4]] -> 2
      Explanation: For this input, the correct result is 2.
    - Input: n=5, edges=[[0,1],[1,2],[2,3],[3,4]] -> 1
      Explanation: For this input, the correct result is 1.

Implement:
    int SolveNumberOfConnectedComponentsInAnUndirectedGraph(int n, const std::vector<std::vector<int>>& edges);
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
int SolveNumberOfConnectedComponentsInAnUndirectedGraph(int n, const std::vector<std::vector<int>>& edges) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: n=5, edges=[[0,1],[1,2],[3,4]] -> 2
    // Explanation: For this input, the correct result is 2.
    // Case 2: Input: n=5, edges=[[0,1],[1,2],[2,3],[3,4]] -> 1
    // Explanation: For this input, the correct result is 1.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveNumberOfConnectedComponentsInAnUndirectedGraph(0, {});
    return true;
}

RUN_TESTS()
