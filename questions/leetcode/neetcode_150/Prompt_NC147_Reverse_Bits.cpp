// NeetCode 150 NC147: Reverse Bits
// Topic: Bit Manipulation
// Difficulty: Easy
// Source: https://leetcode.com/problems/reverse-bits/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Reverse the bits of a 32-bit unsigned integer.

Examples:
    - Input: 00000010100101000001111010011100 -> 964176192
      Explanation: For this input, the correct result is 964176192.
    - Input: 11111111111111111111111111111101 -> 3221225471
      Explanation: For this input, the correct result is 3221225471.

Implement:
    uint32_t SolveReverseBits(uint32_t n);
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
uint32_t SolveReverseBits(uint32_t n) {
    // TODO: implement.
    return 0u;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: 00000010100101000001111010011100 -> 964176192
    // Explanation: For this input, the correct result is 964176192.
    // Case 2: Input: 11111111111111111111111111111101 -> 3221225471
    // Explanation: For this input, the correct result is 3221225471.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveReverseBits(0u);
    return true;
}

RUN_TESTS()
