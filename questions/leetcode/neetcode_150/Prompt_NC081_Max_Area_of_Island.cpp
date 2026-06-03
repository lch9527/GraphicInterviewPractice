// NeetCode 150 NC081: Max Area of Island
// Topic: Graphs
// Difficulty: Medium
// Source: https://leetcode.com/problems/max-area-of-island/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the largest area among connected groups of land cells.

Examples:
    - Input: grid with one island of area 6 -> 6
      Explanation: For this input, the correct result is 6.
    - Input: all water -> 0
      Explanation: For this input, the correct result is 0.

Implement:
    int SolveMaxAreaOfIsland(std::vector<std::vector<int>>& grid);
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
int SolveMaxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: grid with one island of area 6 -> 6
    // Explanation: For this input, the correct result is 6.
    // Case 2: Input: all water -> 0
    // Explanation: For this input, the correct result is 0.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    std::vector<std::vector<int>> arg0{};
    (void)SolveMaxAreaOfIsland(arg0);
    return true;
}

RUN_TESTS()
