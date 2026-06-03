// NeetCode 150 NC003: Two Sum
// Topic: Arrays & Hashing
// Difficulty: Easy
// Source: https://leetcode.com/problems/two-sum/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Given numbers and a target, return the indices of two distinct numbers whose sum equals the target.

Examples:
    - Input: nums=[2,7,11,15], target=9 -> [0,1]
      Explanation: For this input, the correct result is [0,1].
    - Input: nums=[3,2,4], target=6 -> [1,2]
      Explanation: For this input, the correct result is [1,2].

Implement:
    std::vector<int> SolveTwoSum(const std::vector<int>& nums, int target);
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
std::vector<int> SolveTwoSum(const std::vector<int>& nums, int target) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: nums=[2,7,11,15], target=9 -> [0,1]
    // Explanation: For this input, the correct result is [0,1].
    // Case 2: Input: nums=[3,2,4], target=6 -> [1,2]
    // Explanation: For this input, the correct result is [1,2].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveTwoSum({}, 0);
    return true;
}

RUN_TESTS()
