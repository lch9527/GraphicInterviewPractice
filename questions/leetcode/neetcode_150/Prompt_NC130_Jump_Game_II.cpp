// NeetCode 150 NC130: Jump Game II
// Topic: Greedy
// Difficulty: Medium
// Source: https://leetcode.com/problems/jump-game-ii/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the minimum jumps needed to reach the last index.

Examples:
    - Input: [2,3,1,1,4] -> 2
      Explanation: For this input, the correct result is 2.
    - Input: [2,3,0,1,4] -> 2
      Explanation: For this input, the correct result is 2.

Implement:
    int SolveJumpGameII(const std::vector<int>& nums);
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
int SolveJumpGameII(const std::vector<int>& nums) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [2,3,1,1,4] -> 2
    // Explanation: For this input, the correct result is 2.
    // Case 2: Input: [2,3,0,1,4] -> 2
    // Explanation: For this input, the correct result is 2.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveJumpGameII({});
    return true;
}

RUN_TESTS()
