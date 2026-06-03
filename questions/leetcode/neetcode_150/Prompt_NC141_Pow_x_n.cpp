// NeetCode 150 NC141: Pow x n
// Topic: Math & Geometry
// Difficulty: Medium
// Source: https://leetcode.com/problems/powx-n/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Compute x raised to integer power n efficiently.

Examples:
    - Input: x=2.0, n=10 -> 1024.0
      Explanation: For this input, the correct result is 1024.0.
    - Input: x=2.0, n=-2 -> 0.25
      Explanation: For this input, the correct result is 0.25.

Implement:
    double SolvePowXN(double x, int n);
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
double SolvePowXN(double x, int n) {
    // TODO: implement.
    return 0.0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: x=2.0, n=10 -> 1024.0
    // Explanation: For this input, the correct result is 1024.0.
    // Case 2: Input: x=2.0, n=-2 -> 0.25
    // Explanation: For this input, the correct result is 0.25.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolvePowXN(0.0, 0);
    return true;
}

RUN_TESTS()
