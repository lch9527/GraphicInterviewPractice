// NeetCode 150 NC037: Linked List Cycle
// Topic: Linked List
// Difficulty: Easy
// Source: https://leetcode.com/problems/linked-list-cycle/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return whether a linked list contains a cycle.

Examples:
    - Input: list with tail connecting to index 1 -> true
      Explanation: For this input, the correct result is true.
    - Input: list with no cycle -> false
      Explanation: For this input, the correct result is false.

Implement:
    bool SolveLinkedListCycle(ListNode* head);
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
bool SolveLinkedListCycle(ListNode* head) {
    // TODO: implement.
    return false;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: list with tail connecting to index 1 -> true
    // Explanation: For this input, the correct result is true.
    // Case 2: Input: list with no cycle -> false
    // Explanation: For this input, the correct result is false.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveLinkedListCycle(nullptr);
    return true;
}

RUN_TESTS()
