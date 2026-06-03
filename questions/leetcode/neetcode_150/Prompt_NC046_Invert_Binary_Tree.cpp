// NeetCode 150 NC046: Invert Binary Tree
// Topic: Trees
// Difficulty: Easy
// Source: https://leetcode.com/problems/invert-binary-tree/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Swap every node's left and right child and return the root.

Examples:
    - Input: tree [4,2,7,1,3,6,9] -> [4,7,2,9,6,3,1]
      Explanation: For this input, the correct result is [4,7,2,9,6,3,1].
    - Input: empty tree -> empty tree
      Explanation: For this input, the correct result is empty tree.

Implement:
    TreeNode* SolveInvertBinaryTree(TreeNode* root);
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
TreeNode* SolveInvertBinaryTree(TreeNode* root) {
    // TODO: implement.
    return nullptr;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: tree [4,2,7,1,3,6,9] -> [4,7,2,9,6,3,1]
    // Explanation: For this input, the correct result is [4,7,2,9,6,3,1].
    // Case 2: Input: empty tree -> empty tree
    // Explanation: For this input, the correct result is empty tree.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveInvertBinaryTree(nullptr);
    return true;
}

RUN_TESTS()
