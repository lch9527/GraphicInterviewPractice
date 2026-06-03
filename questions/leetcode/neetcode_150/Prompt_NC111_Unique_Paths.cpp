// NeetCode 150 NC111: Unique Paths
// Topic: Dynamic Programming
// Difficulty: Medium
// Source: https://leetcode.com/problems/unique-paths/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Count paths from top-left to bottom-right in an m x n grid moving only down or right.

Examples:
    - Input: m=3, n=7 -> 28
      Explanation: For this input, the correct result is 28.
    - Input: m=3, n=2 -> 3
      Explanation: For this input, the correct result is 3.

Implement:
    int SolveUniquePaths(int m, int n);
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
int SolveUniquePaths(int m, int n) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: m=3, n=7 -> 28
    // Explanation: For this input, the correct result is 28.
    // Case 2: Input: m=3, n=2 -> 3
    // Explanation: For this input, the correct result is 3.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveUniquePaths(0, 0);
    return true;
}

RUN_TESTS()
