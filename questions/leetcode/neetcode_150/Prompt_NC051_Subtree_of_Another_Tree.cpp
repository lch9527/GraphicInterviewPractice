// NeetCode 150 NC051: Subtree of Another Tree
// Topic: Trees
// Difficulty: Easy
// Source: https://leetcode.com/problems/subtree-of-another-tree/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return whether one tree is exactly a subtree of another tree.

Examples:
    - Input: root=[3,4,5,1,2], subRoot=[4,1,2] -> true
      Explanation: For this input, the correct result is true.
    - Input with extra child under 2 -> false
      Explanation: This example should produce false.

Implement:
    bool SolveSubtreeOfAnotherTree(TreeNode* root, TreeNode* subRoot);
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
bool SolveSubtreeOfAnotherTree(TreeNode* root, TreeNode* subRoot) {
    // TODO: implement.
    return false;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: root=[3,4,5,1,2], subRoot=[4,1,2] -> true
    // Explanation: For this input, the correct result is true.
    // Case 2: Input with extra child under 2 -> false
    // Explanation: This example should produce false.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveSubtreeOfAnotherTree(nullptr, nullptr);
    return true;
}

RUN_TESTS()
