// NeetCode 150 NC014: Trapping Rain Water
// Topic: Two Pointers
// Difficulty: Hard
// Source: https://leetcode.com/problems/trapping-rain-water/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Given bar heights, compute the total water trapped between bars after rain.

Examples:
    - Input: [0,1,0,2,1,0,1,3,2,1,2,1] -> 6
      Explanation: For this input, the correct result is 6.
    - Input: [4,2,0,3,2,5] -> 9
      Explanation: For this input, the correct result is 9.

Implement:
    int SolveTrappingRainWater(const std::vector<int>& height);
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
int SolveTrappingRainWater(const std::vector<int>& height) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [0,1,0,2,1,0,1,3,2,1,2,1] -> 6
    // Explanation: For this input, the correct result is 6.
    // Case 2: Input: [4,2,0,3,2,5] -> 9
    // Explanation: For this input, the correct result is 9.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveTrappingRainWater({});
    return true;
}

RUN_TESTS()
