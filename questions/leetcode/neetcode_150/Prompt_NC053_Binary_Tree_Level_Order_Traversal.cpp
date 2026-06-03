// NeetCode 150 NC053: Binary Tree Level Order Traversal
// Topic: Trees
// Difficulty: Medium
// Source: https://leetcode.com/problems/binary-tree-level-order-traversal/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return binary-tree values level by level from top to bottom.

Examples:
    - Input: [3,9,20,null,null,15,7] -> [[3],[9,20],[15,7]]
      Explanation: For this input, the correct result is [[3],[9,20],[15,7]].
    - Input: [1] -> [[1]]
      Explanation: For this input, the correct result is [[1]].

Implement:
    std::vector<std::vector<int>> SolveBinaryTreeLevelOrderTraversal(TreeNode* root);
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
std::vector<std::vector<int>> SolveBinaryTreeLevelOrderTraversal(TreeNode* root) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [3,9,20,null,null,15,7] -> [[3],[9,20],[15,7]]
    // Explanation: For this input, the correct result is [[3],[9,20],[15,7]].
    // Case 2: Input: [1] -> [[1]]
    // Explanation: For this input, the correct result is [[1]].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveBinaryTreeLevelOrderTraversal(nullptr);
    return true;
}

RUN_TESTS()
