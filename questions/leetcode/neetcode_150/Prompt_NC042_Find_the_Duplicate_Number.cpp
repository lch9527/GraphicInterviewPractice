// NeetCode 150 NC042: Find the Duplicate Number
// Topic: Linked List
// Difficulty: Medium
// Source: https://leetcode.com/problems/find-the-duplicate-number/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Find the repeated number in an array containing n+1 values in [1,n].

Examples:
    - Input: [1,3,4,2,2] -> 2
      Explanation: For this input, the correct result is 2.
    - Input: [3,1,3,4,2] -> 3
      Explanation: For this input, the correct result is 3.

Implement:
    int SolveFindTheDuplicateNumber(const std::vector<int>& nums);
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
int SolveFindTheDuplicateNumber(const std::vector<int>& nums) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [1,3,4,2,2] -> 2
    // Explanation: For this input, the correct result is 2.
    // Case 2: Input: [3,1,3,4,2] -> 3
    // Explanation: For this input, the correct result is 3.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveFindTheDuplicateNumber({});
    return true;
}

RUN_TESTS()
