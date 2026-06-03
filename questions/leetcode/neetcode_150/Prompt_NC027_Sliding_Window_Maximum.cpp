// NeetCode 150 NC027: Sliding Window Maximum
// Topic: Sliding Window
// Difficulty: Hard
// Source: https://leetcode.com/problems/sliding-window-maximum/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the maximum value in every contiguous window of size k.

Examples:
    - Input: nums=[1,3,-1,-3,5,3,6,7], k=3 -> [3,3,5,5,6,7]
      Explanation: For this input, the correct result is [3,3,5,5,6,7].
    - Input: nums=[1], k=1 -> [1]
      Explanation: For this input, the correct result is [1].

Implement:
    std::vector<int> SolveSlidingWindowMaximum(const std::vector<int>& nums, int k);
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
std::vector<int> SolveSlidingWindowMaximum(const std::vector<int>& nums, int k) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: nums=[1,3,-1,-3,5,3,6,7], k=3 -> [3,3,5,5,6,7]
    // Explanation: For this input, the correct result is [3,3,5,5,6,7].
    // Case 2: Input: nums=[1], k=1 -> [1]
    // Explanation: For this input, the correct result is [1].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveSlidingWindowMaximum({}, 0);
    return true;
}

RUN_TESTS()
