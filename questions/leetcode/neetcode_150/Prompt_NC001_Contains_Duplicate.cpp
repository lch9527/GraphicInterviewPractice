// NeetCode 150 NC001: Contains Duplicate
// Topic: Arrays & Hashing
// Difficulty: Easy
// Source: https://leetcode.com/problems/contains-duplicate/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Given an integer array, determine whether any value appears at least twice.

Examples:
    - Input: [1,2,3,1] -> true
      Explanation: For this input, the correct result is true.
    - Input: [1,2,3,4] -> false
      Explanation: For this input, the correct result is false.

Implement:
    bool SolveContainsDuplicate(const std::vector<int>& nums);
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
bool SolveContainsDuplicate(const std::vector<int>& nums) {
    // TODO: implement.
    return false;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [1,2,3,1] -> true
    // Explanation: For this input, the correct result is true.
    // Case 2: Input: [1,2,3,4] -> false
    // Explanation: For this input, the correct result is false.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveContainsDuplicate({});
    return true;
}

RUN_TESTS()
