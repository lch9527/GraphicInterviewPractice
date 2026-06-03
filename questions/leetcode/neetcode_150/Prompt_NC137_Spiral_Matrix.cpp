// NeetCode 150 NC137: Spiral Matrix
// Topic: Math & Geometry
// Difficulty: Medium
// Source: https://leetcode.com/problems/spiral-matrix/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return all matrix elements in spiral order.

Examples:
    - Input: [[1,2,3],[4,5,6],[7,8,9]] -> [1,2,3,6,9,8,7,4,5]
      Explanation: For this input, the correct result is [1,2,3,6,9,8,7,4,5].
    - Input: [[1,2,3,4],[5,6,7,8],[9,10,11,12]] -> [1,2,3,4,8,12,11,10,9,5,6,7]
      Explanation: For this input, the correct result is [1,2,3,4,8,12,11,10,9,5,6,7].

Implement:
    std::vector<int> SolveSpiralMatrix(const std::vector<std::vector<int>>& matrix);
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
std::vector<int> SolveSpiralMatrix(const std::vector<std::vector<int>>& matrix) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [[1,2,3],[4,5,6],[7,8,9]] -> [1,2,3,6,9,8,7,4,5]
    // Explanation: For this input, the correct result is [1,2,3,6,9,8,7,4,5].
    // Case 2: Input: [[1,2,3,4],[5,6,7,8],[9,10,11,12]] -> [1,2,3,4,8,12,11,10,9,5,6,7]
    // Explanation: For this input, the correct result is [1,2,3,4,8,12,11,10,9,5,6,7].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveSpiralMatrix({});
    return true;
}

RUN_TESTS()
