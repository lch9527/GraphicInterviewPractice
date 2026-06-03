// NeetCode 150 NC145: Number of 1 Bits
// Topic: Bit Manipulation
// Difficulty: Easy
// Source: https://leetcode.com/problems/number-of-1-bits/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the count of set bits in an unsigned integer.

Examples:
    - Input: 00000000000000000000000000001011 -> 3
      Explanation: For this input, the correct result is 3.
    - Input: 00000000000000000000000010000000 -> 1
      Explanation: For this input, the correct result is 1.

Implement:
    int SolveNumberOf1Bits(uint32_t n);
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
int SolveNumberOf1Bits(uint32_t n) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: 00000000000000000000000000001011 -> 3
    // Explanation: For this input, the correct result is 3.
    // Case 2: Input: 00000000000000000000000010000000 -> 1
    // Explanation: For this input, the correct result is 1.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveNumberOf1Bits(0u);
    return true;
}

RUN_TESTS()
