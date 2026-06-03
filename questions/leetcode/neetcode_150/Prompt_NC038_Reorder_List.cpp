// NeetCode 150 NC038: Reorder List
// Topic: Linked List
// Difficulty: Medium
// Source: https://leetcode.com/problems/reorder-list/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Reorder a list as first, last, second, second-last, and so on in place.

Examples:
    - Input: 1->2->3->4 -> 1->4->2->3
      Explanation: For this input, the correct result is 1->4->2->3.
    - Input: 1->2->3->4->5 -> 1->5->2->4->3
      Explanation: For this input, the correct result is 1->5->2->4->3.

Implement:
    void SolveReorderList(ListNode* head);
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
void SolveReorderList(ListNode* head) {
    // TODO: implement.
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: 1->2->3->4 -> 1->4->2->3
    // Explanation: For this input, the correct result is 1->4->2->3.
    // Case 2: Input: 1->2->3->4->5 -> 1->5->2->4->3
    // Explanation: For this input, the correct result is 1->5->2->4->3.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    SolveReorderList(nullptr);
    return true;
}

RUN_TESTS()
