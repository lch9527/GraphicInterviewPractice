// NeetCode 150 NC016: Min Stack
// Topic: Stack
// Difficulty: Medium
// Source: https://leetcode.com/problems/min-stack/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Design a stack that supports push, pop, top, and retrieving the minimum in constant time.

Examples:
    - Operations: push(-2), push(0), push(-3), getMin() -> -3
      Explanation: After performing the listed operations, the observed result should be -3.
    - After pop(), top() -> 0 and getMin() -> -2
      Explanation: This example should produce 0 and getMin() -> -2.

Implement:
    Implement the class shown below.
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
class MinStack { public: void Push(int value) { (void)value; } void Pop() {} int Top() const { return 0; } int GetMin() const { return 0; } };

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Operations: push(-2), push(0), push(-3), getMin() -> -3
    // Explanation: After performing the listed operations, the observed result should be -3.
    // Case 2: After pop(), top() -> 0 and getMin() -> -2
    // Explanation: This example should produce 0 and getMin() -> -2.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    MinStack value; value.Push(0); value.Pop();
    return true;
}

RUN_TESTS()
