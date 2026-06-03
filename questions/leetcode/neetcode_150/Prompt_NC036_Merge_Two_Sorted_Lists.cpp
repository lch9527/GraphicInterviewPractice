// NeetCode 150 NC036: Merge Two Sorted Lists
// Topic: Linked List
// Difficulty: Easy
// Source: https://leetcode.com/problems/merge-two-sorted-lists/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Merge two sorted linked lists into one sorted list.

Examples:
    - Input: 1->2->4 and 1->3->4 -> 1->1->2->3->4->4
      Explanation: For this input, the correct result is 1->1->2->3->4->4.
    - Input: empty and 0 -> 0
      Explanation: For this input, the correct result is 0.

Implement:
    ListNode* SolveMergeTwoSortedLists(ListNode* list1, ListNode* list2);
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
ListNode* SolveMergeTwoSortedLists(ListNode* list1, ListNode* list2) {
    // TODO: implement.
    return nullptr;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: 1->2->4 and 1->3->4 -> 1->1->2->3->4->4
    // Explanation: For this input, the correct result is 1->1->2->3->4->4.
    // Case 2: Input: empty and 0 -> 0
    // Explanation: For this input, the correct result is 0.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveMergeTwoSortedLists(nullptr, nullptr);
    return true;
}

RUN_TESTS()
