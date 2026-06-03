// NeetCode 150 NC150: Reverse Integer
// Topic: Bit Manipulation
// Difficulty: Medium
// Source: https://leetcode.com/problems/reverse-integer/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Reverse digits of a signed 32-bit integer, returning 0 on overflow.

Examples:
    - Input: x=123 -> 321
      Explanation: For this input, the correct result is 321.
    - Input: x=-123 -> -321
      Explanation: For this input, the correct result is -321.

Implement:
    int SolveReverseInteger(int x);
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
int SolveReverseInteger(int x) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: x=123 -> 321
    // Explanation: For this input, the correct result is 321.
    // Case 2: Input: x=-123 -> -321
    // Explanation: For this input, the correct result is -321.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveReverseInteger(0);
    return true;
}

RUN_TESTS()
