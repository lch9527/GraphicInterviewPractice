// NeetCode 150 NC100: Min Cost Climbing Stairs
// Topic: Dynamic Programming
// Difficulty: Easy
// Source: https://leetcode.com/problems/min-cost-climbing-stairs/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the minimum cost to reach the top when you may climb 1 or 2 steps.

Examples:
    - Input: [10,15,20] -> 15
      Explanation: For this input, the correct result is 15.
    - Input: [1,100,1,1,1,100,1,1,100,1] -> 6
      Explanation: For this input, the correct result is 6.

Implement:
    int SolveMinCostClimbingStairs(const std::vector<int>& cost);
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
int SolveMinCostClimbingStairs(const std::vector<int>& cost) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [10,15,20] -> 15
    // Explanation: For this input, the correct result is 15.
    // Case 2: Input: [1,100,1,1,1,100,1,1,100,1] -> 6
    // Explanation: For this input, the correct result is 6.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveMinCostClimbingStairs({});
    return true;
}

RUN_TESTS()
