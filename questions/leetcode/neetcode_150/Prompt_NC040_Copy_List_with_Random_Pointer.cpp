// NeetCode 150 NC040: Copy List with Random Pointer
// Topic: Linked List
// Difficulty: Medium
// Source: https://leetcode.com/problems/copy-list-with-random-pointer/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Deep-copy a linked list where each node has next and random pointers.

Examples:
    - Input: nodes with next/random links -> structurally identical copy with distinct nodes
      Explanation: For this input, the correct result is structurally identical copy with distinct nodes.
    - Input: empty list -> empty list
      Explanation: For this input, the correct result is empty list.

Implement:
    RandomNode* SolveCopyListWithRandomPointer(RandomNode* head);
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
RandomNode* SolveCopyListWithRandomPointer(RandomNode* head) {
    // TODO: implement.
    return nullptr;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: nodes with next/random links -> structurally identical copy with distinct nodes
    // Explanation: For this input, the correct result is structurally identical copy with distinct nodes.
    // Case 2: Input: empty list -> empty list
    // Explanation: For this input, the correct result is empty list.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveCopyListWithRandomPointer(nullptr);
    return true;
}

RUN_TESTS()
