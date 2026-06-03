// NeetCode 150 NC039: Remove Nth Node From End of List
// Topic: Linked List
// Difficulty: Medium
// Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Remove the nth node from the end of a linked list.

Examples:
    - Input: head=1->2->3->4->5, n=2 -> 1->2->3->5
      Explanation: For this input, the correct result is 1->2->3->5.
    - Input: head=1, n=1 -> empty
      Explanation: For this input, the correct result is empty.

Implement:
    ListNode* SolveRemoveNthNodeFromEndOfList(ListNode* head, int n);
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
ListNode* SolveRemoveNthNodeFromEndOfList(ListNode* head, int n) {
    // TODO: implement.
    return nullptr;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: head=1->2->3->4->5, n=2 -> 1->2->3->5
    // Explanation: For this input, the correct result is 1->2->3->5.
    // Case 2: Input: head=1, n=1 -> empty
    // Explanation: For this input, the correct result is empty.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveRemoveNthNodeFromEndOfList(nullptr, 0);
    return true;
}

RUN_TESTS()
