// NeetCode 150 NC115: Target Sum
// Topic: Dynamic Programming
// Difficulty: Medium
// Source: https://leetcode.com/problems/target-sum/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Count ways to assign plus/minus signs so numbers sum to target.

Examples:
    - Input: nums=[1,1,1,1,1], target=3 -> 5
      Explanation: For this input, the correct result is 5.
    - Input: nums=[1], target=1 -> 1
      Explanation: For this input, the correct result is 1.

Implement:
    int SolveTargetSum(const std::vector<int>& nums, int target);
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
int SolveTargetSum(const std::vector<int>& nums, int target) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: nums=[1,1,1,1,1], target=3 -> 5
    // Explanation: For this input, the correct result is 5.
    // Case 2: Input: nums=[1], target=1 -> 1
    // Explanation: For this input, the correct result is 1.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveTargetSum({}, 0);
    return true;
}

RUN_TESTS()
