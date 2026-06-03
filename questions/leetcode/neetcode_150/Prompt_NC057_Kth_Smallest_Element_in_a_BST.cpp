// NeetCode 150 NC057: Kth Smallest Element in a BST
// Topic: Trees
// Difficulty: Medium
// Source: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the kth smallest value in a binary search tree.

Examples:
    - Input: root=[3,1,4,null,2], k=1 -> 1
      Explanation: For this input, the correct result is 1.
    - Input: root=[5,3,6,2,4,null,null,1], k=3 -> 3
      Explanation: For this input, the correct result is 3.

Implement:
    int SolveKthSmallestElementInABST(TreeNode* root, int k);
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
int SolveKthSmallestElementInABST(TreeNode* root, int k) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: root=[3,1,4,null,2], k=1 -> 1
    // Explanation: For this input, the correct result is 1.
    // Case 2: Input: root=[5,3,6,2,4,null,null,1], k=3 -> 3
    // Explanation: For this input, the correct result is 3.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveKthSmallestElementInABST(nullptr, 0);
    return true;
}

RUN_TESTS()
