// NeetCode 150 NC028: Binary Search
// Topic: Binary Search
// Difficulty: Easy
// Source: https://leetcode.com/problems/binary-search/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the index of target in a sorted array, or -1 if not found.

Examples:
    - Input: nums=[-1,0,3,5,9,12], target=9 -> 4
      Explanation: For this input, the correct result is 4.
    - Input: target=2 -> -1
      Explanation: For this input, the correct result is -1.

Implement:
    int SolveBinarySearch(const std::vector<int>& nums, int target);
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
int SolveBinarySearch(const std::vector<int>& nums, int target) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: nums=[-1,0,3,5,9,12], target=9 -> 4
    // Explanation: For this input, the correct result is 4.
    // Case 2: Input: target=2 -> -1
    // Explanation: For this input, the correct result is -1.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveBinarySearch({}, 0);
    return true;
}

RUN_TESTS()
