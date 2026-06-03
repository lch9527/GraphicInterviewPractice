// NeetCode 150 NC059: Binary Tree Maximum Path Sum
// Topic: Trees
// Difficulty: Hard
// Source: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the maximum path sum of any non-empty path in a binary tree.

Examples:
    - Input: [1,2,3] -> 6
      Explanation: For this input, the correct result is 6.
    - Input: [-10,9,20,null,null,15,7] -> 42
      Explanation: For this input, the correct result is 42.

Implement:
    int SolveBinaryTreeMaximumPathSum(TreeNode* root);
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
int SolveBinaryTreeMaximumPathSum(TreeNode* root) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [1,2,3] -> 6
    // Explanation: For this input, the correct result is 6.
    // Case 2: Input: [-10,9,20,null,null,15,7] -> 42
    // Explanation: For this input, the correct result is 42.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveBinaryTreeMaximumPathSum(nullptr);
    return true;
}

RUN_TESTS()
