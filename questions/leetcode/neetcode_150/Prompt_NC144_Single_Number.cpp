// NeetCode 150 NC144: Single Number
// Topic: Bit Manipulation
// Difficulty: Easy
// Source: https://leetcode.com/problems/single-number/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the value that appears once when every other value appears twice.

Examples:
    - Input: [2,2,1] -> 1
      Explanation: For this input, the correct result is 1.
    - Input: [4,1,2,1,2] -> 4
      Explanation: For this input, the correct result is 4.

Implement:
    int SolveSingleNumber(const std::vector<int>& nums);
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
int SolveSingleNumber(const std::vector<int>& nums) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [2,2,1] -> 1
    // Explanation: For this input, the correct result is 1.
    // Case 2: Input: [4,1,2,1,2] -> 4
    // Explanation: For this input, the correct result is 4.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveSingleNumber({});
    return true;
}

RUN_TESTS()
