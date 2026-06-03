// NeetCode 150 NC099: Climbing Stairs
// Topic: Dynamic Programming
// Difficulty: Easy
// Source: https://leetcode.com/problems/climbing-stairs/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Count distinct ways to climb n stairs taking 1 or 2 steps at a time.

Examples:
    - Input: n=2 -> 2
      Explanation: For this input, the correct result is 2.
    - Input: n=3 -> 3
      Explanation: For this input, the correct result is 3.

Implement:
    int SolveClimbingStairs(int n);
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
int SolveClimbingStairs(int n) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: n=2 -> 2
    // Explanation: For this input, the correct result is 2.
    // Case 2: Input: n=3 -> 3
    // Explanation: For this input, the correct result is 3.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveClimbingStairs(0);
    return true;
}

RUN_TESTS()
