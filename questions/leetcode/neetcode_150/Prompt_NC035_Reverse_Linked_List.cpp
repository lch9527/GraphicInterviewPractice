// NeetCode 150 NC035: Reverse Linked List
// Topic: Linked List
// Difficulty: Easy
// Source: https://leetcode.com/problems/reverse-linked-list/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Reverse a singly linked list and return the new head.

Examples:
    - Input: 1->2->3->4->5 -> 5->4->3->2->1
      Explanation: For this input, the correct result is 5->4->3->2->1.
    - Input: empty list -> empty list
      Explanation: For this input, the correct result is empty list.

Implement:
    ListNode* SolveReverseLinkedList(ListNode* head);
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
ListNode* SolveReverseLinkedList(ListNode* head) {
    // TODO: implement.
    return nullptr;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: 1->2->3->4->5 -> 5->4->3->2->1
    // Explanation: For this input, the correct result is 5->4->3->2->1.
    // Case 2: Input: empty list -> empty list
    // Explanation: For this input, the correct result is empty list.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveReverseLinkedList(nullptr);
    return true;
}

RUN_TESTS()
