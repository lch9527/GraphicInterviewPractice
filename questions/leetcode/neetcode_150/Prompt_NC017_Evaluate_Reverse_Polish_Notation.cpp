// NeetCode 150 NC017: Evaluate Reverse Polish Notation
// Topic: Stack
// Difficulty: Medium
// Source: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Evaluate an arithmetic expression written in postfix notation.

Examples:
    - Input: ["2","1","+","3","*"] -> 9
      Explanation: For this input, the correct result is 9.
    - Input: ["4","13","5","/","+"] -> 6
      Explanation: For this input, the correct result is 6.

Implement:
    int SolveEvaluateReversePolishNotation(const std::vector<std::string>& tokens);
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
int SolveEvaluateReversePolishNotation(const std::vector<std::string>& tokens) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: ["2","1","+","3","*"] -> 9
    // Explanation: For this input, the correct result is 9.
    // Case 2: Input: ["4","13","5","/","+"] -> 6
    // Explanation: For this input, the correct result is 6.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveEvaluateReversePolishNotation("");
    return true;
}

RUN_TESTS()
