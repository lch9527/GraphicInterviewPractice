// NeetCode 150 NC018: Generate Parentheses
// Topic: Stack
// Difficulty: Medium
// Source: https://leetcode.com/problems/generate-parentheses/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Generate all valid parentheses strings containing n pairs.

Examples:
    - Input: n=3 -> ["((()))","(()())","(())()","()(())","()()()"]
      Explanation: For this input, the correct result is ["((()))","(()())","(())()","()(())","()()()"].
    - Input: n=1 -> ["()"]
      Explanation: For this input, the correct result is ["()"].

Implement:
    std::vector<std::string> SolveGenerateParentheses(int n);
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
std::vector<std::string> SolveGenerateParentheses(int n) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: n=3 -> ["((()))","(()())","(())()","()(())","()()()"]
    // Explanation: For this input, the correct result is ["((()))","(()())","(())()","()(())","()()()"].
    // Case 2: Input: n=1 -> ["()"]
    // Explanation: For this input, the correct result is ["()"].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveGenerateParentheses(0);
    return true;
}

RUN_TESTS()
