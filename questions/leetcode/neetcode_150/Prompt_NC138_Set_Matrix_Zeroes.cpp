// NeetCode 150 NC138: Set Matrix Zeroes
// Topic: Math & Geometry
// Difficulty: Medium
// Source: https://leetcode.com/problems/set-matrix-zeroes/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    If a matrix cell is zero, set its entire row and column to zero in place.

Examples:
    - Input: [[1,1,1],[1,0,1],[1,1,1]] -> [[1,0,1],[0,0,0],[1,0,1]]
      Explanation: For this input, the correct result is [[1,0,1],[0,0,0],[1,0,1]].
    - Input: [[0,1,2,0],[3,4,5,2],[1,3,1,5]] -> rows/cols zeroed
      Explanation: For this input, the correct result is rows/cols zeroed.

Implement:
    void SolveSetMatrixZeroes(std::vector<std::vector<int>>& matrix);
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
void SolveSetMatrixZeroes(std::vector<std::vector<int>>& matrix) {
    // TODO: implement.
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [[1,1,1],[1,0,1],[1,1,1]] -> [[1,0,1],[0,0,0],[1,0,1]]
    // Explanation: For this input, the correct result is [[1,0,1],[0,0,0],[1,0,1]].
    // Case 2: Input: [[0,1,2,0],[3,4,5,2],[1,3,1,5]] -> rows/cols zeroed
    // Explanation: For this input, the correct result is rows/cols zeroed.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    std::vector<std::vector<int>> arg0{};
    SolveSetMatrixZeroes(arg0);
    return true;
}

RUN_TESTS()
