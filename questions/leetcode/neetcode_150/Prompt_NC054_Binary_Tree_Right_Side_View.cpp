// NeetCode 150 NC054: Binary Tree Right Side View
// Topic: Trees
// Difficulty: Medium
// Source: https://leetcode.com/problems/binary-tree-right-side-view/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the values visible when looking at a binary tree from the right side.

Examples:
    - Input: [1,2,3,null,5,null,4] -> [1,3,4]
      Explanation: For this input, the correct result is [1,3,4].
    - Input: [1,null,3] -> [1,3]
      Explanation: For this input, the correct result is [1,3].

Implement:
    std::vector<int> SolveBinaryTreeRightSideView(TreeNode* root);
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
std::vector<int> SolveBinaryTreeRightSideView(TreeNode* root) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [1,2,3,null,5,null,4] -> [1,3,4]
    // Explanation: For this input, the correct result is [1,3,4].
    // Case 2: Input: [1,null,3] -> [1,3]
    // Explanation: For this input, the correct result is [1,3].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveBinaryTreeRightSideView(nullptr);
    return true;
}

RUN_TESTS()
