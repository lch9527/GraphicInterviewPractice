// NeetCode 150 NC056: Validate Binary Search Tree
// Topic: Trees
// Difficulty: Medium
// Source: https://leetcode.com/problems/validate-binary-search-tree/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return whether a binary tree satisfies strict BST ordering for every node.

Examples:
    - Input: [2,1,3] -> true
      Explanation: For this input, the correct result is true.
    - Input: [5,1,4,null,null,3,6] -> false
      Explanation: For this input, the correct result is false.

Implement:
    bool SolveValidateBinarySearchTree(TreeNode* root);
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
bool SolveValidateBinarySearchTree(TreeNode* root) {
    // TODO: implement.
    return false;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [2,1,3] -> true
    // Explanation: For this input, the correct result is true.
    // Case 2: Input: [5,1,4,null,null,3,6] -> false
    // Explanation: For this input, the correct result is false.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveValidateBinarySearchTree(nullptr);
    return true;
}

RUN_TESTS()
