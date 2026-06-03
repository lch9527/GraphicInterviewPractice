// NeetCode 150 NC049: Balanced Binary Tree
// Topic: Trees
// Difficulty: Easy
// Source: https://leetcode.com/problems/balanced-binary-tree/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return whether every node's left and right subtree heights differ by at most one.

Examples:
    - Input: [3,9,20,null,null,15,7] -> true
      Explanation: For this input, the correct result is true.
    - Input: [1,2,2,3,3,null,null,4,4] -> false
      Explanation: For this input, the correct result is false.

Implement:
    bool SolveBalancedBinaryTree(TreeNode* root);
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
bool SolveBalancedBinaryTree(TreeNode* root) {
    // TODO: implement.
    return false;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [3,9,20,null,null,15,7] -> true
    // Explanation: For this input, the correct result is true.
    // Case 2: Input: [1,2,2,3,3,null,null,4,4] -> false
    // Explanation: For this input, the correct result is false.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveBalancedBinaryTree(nullptr);
    return true;
}

RUN_TESTS()
