// NeetCode 150 NC146: Counting Bits
// Topic: Bit Manipulation
// Difficulty: Easy
// Source: https://leetcode.com/problems/counting-bits/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    For every i from 0 to n, return the number of set bits in i.

Examples:
    - Input: n=2 -> [0,1,1]
      Explanation: For this input, the correct result is [0,1,1].
    - Input: n=5 -> [0,1,1,2,1,2]
      Explanation: For this input, the correct result is [0,1,1,2,1,2].

Implement:
    std::vector<int> SolveCountingBits(int n);
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
std::vector<int> SolveCountingBits(int n) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: n=2 -> [0,1,1]
    // Explanation: For this input, the correct result is [0,1,1].
    // Case 2: Input: n=5 -> [0,1,1,2,1,2]
    // Explanation: For this input, the correct result is [0,1,1,2,1,2].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveCountingBits(0);
    return true;
}

RUN_TESTS()
