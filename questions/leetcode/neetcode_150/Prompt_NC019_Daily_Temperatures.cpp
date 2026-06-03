// NeetCode 150 NC019: Daily Temperatures
// Topic: Stack
// Difficulty: Medium
// Source: https://leetcode.com/problems/daily-temperatures/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    For each day, return how many days must pass before a warmer temperature occurs.

Examples:
    - Input: [73,74,75,71,69,72,76,73] -> [1,1,4,2,1,1,0,0]
      Explanation: For this input, the correct result is [1,1,4,2,1,1,0,0].
    - Input: [30,40,50,60] -> [1,1,1,0]
      Explanation: For this input, the correct result is [1,1,1,0].

Implement:
    std::vector<int> SolveDailyTemperatures(const std::vector<int>& temperatures);
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
std::vector<int> SolveDailyTemperatures(const std::vector<int>& temperatures) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [73,74,75,71,69,72,76,73] -> [1,1,4,2,1,1,0,0]
    // Explanation: For this input, the correct result is [1,1,4,2,1,1,0,0].
    // Case 2: Input: [30,40,50,60] -> [1,1,1,0]
    // Explanation: For this input, the correct result is [1,1,1,0].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveDailyTemperatures({});
    return true;
}

RUN_TESTS()
