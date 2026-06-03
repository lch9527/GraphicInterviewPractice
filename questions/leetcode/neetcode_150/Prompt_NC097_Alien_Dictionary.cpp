// NeetCode 150 NC097: Alien Dictionary
// Topic: Graphs
// Difficulty: Hard
// Source: https://leetcode.com/problems/alien-dictionary/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Infer a valid character order from sorted words in an alien language.

Examples:
    - Input: ["wrt","wrf","er","ett","rftt"] -> "wertf"
      Explanation: For this input, the correct result is "wertf".
    - Invalid prefix order -> ""
      Explanation: This example should produce "".

Implement:
    std::string SolveAlienDictionary(const std::vector<std::string>& words);
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
std::string SolveAlienDictionary(const std::vector<std::string>& words) {
    // TODO: implement.
    return "";
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: ["wrt","wrf","er","ett","rftt"] -> "wertf"
    // Explanation: For this input, the correct result is "wertf".
    // Case 2: Invalid prefix order -> ""
    // Explanation: This example should produce "".
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveAlienDictionary("");
    return true;
}

RUN_TESTS()
