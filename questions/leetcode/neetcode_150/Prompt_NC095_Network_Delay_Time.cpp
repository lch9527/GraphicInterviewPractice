// NeetCode 150 NC095: Network Delay Time
// Topic: Graphs
// Difficulty: Medium
// Source: https://leetcode.com/problems/network-delay-time/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return how long it takes for a signal to reach every node in a directed weighted graph.

Examples:
    - Input: times=[[2,1,1],[2,3,1],[3,4,1]], n=4, k=2 -> 2
      Explanation: For this input, the correct result is 2.
    - Unreachable node -> -1
      Explanation: This example should produce -1.

Implement:
    int SolveNetworkDelayTime(const std::vector<std::vector<int>>& times, int n, int k);
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
int SolveNetworkDelayTime(const std::vector<std::vector<int>>& times, int n, int k) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: times=[[2,1,1],[2,3,1],[3,4,1]], n=4, k=2 -> 2
    // Explanation: For this input, the correct result is 2.
    // Case 2: Unreachable node -> -1
    // Explanation: This example should produce -1.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveNetworkDelayTime({}, 0, 0);
    return true;
}

RUN_TESTS()
