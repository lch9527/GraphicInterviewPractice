// NeetCode 150 NC041: Add Two Numbers
// Topic: Linked List
// Difficulty: Medium
// Source: https://leetcode.com/problems/add-two-numbers/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Add two non-negative integers stored in reverse-order linked lists.

Examples:
    - Input: 2->4->3 plus 5->6->4 -> 7->0->8
      Explanation: For this input, the correct result is 7->0->8.
    - Input: 0 plus 0 -> 0
      Explanation: For this input, the correct result is 0.

Implement:
    ListNode* SolveAddTwoNumbers(ListNode* l1, ListNode* l2);
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
ListNode* SolveAddTwoNumbers(ListNode* l1, ListNode* l2) {
    // TODO: implement.
    return nullptr;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: 2->4->3 plus 5->6->4 -> 7->0->8
    // Explanation: For this input, the correct result is 7->0->8.
    // Case 2: Input: 0 plus 0 -> 0
    // Explanation: For this input, the correct result is 0.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveAddTwoNumbers(nullptr, nullptr);
    return true;
}

RUN_TESTS()
