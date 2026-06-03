// NeetCode 150 NC077: Palindrome Partitioning
// Topic: Backtracking
// Difficulty: Medium
// Source: https://leetcode.com/problems/palindrome-partitioning/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return all ways to partition a string so every piece is a palindrome.

Examples:
    - Input: "aab" -> [["a","a","b"],["aa","b"]]
      Explanation: For this input, the correct result is [["a","a","b"],["aa","b"]].
    - Input: "a" -> [["a"]]
      Explanation: For this input, the correct result is [["a"]].

Implement:
    std::vector<std::vector<std::string>> SolvePalindromePartitioning(const std::string& s);
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
std::vector<std::vector<std::string>> SolvePalindromePartitioning(const std::string& s) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: "aab" -> [["a","a","b"],["aa","b"]]
    // Explanation: For this input, the correct result is [["a","a","b"],["aa","b"]].
    // Case 2: Input: "a" -> [["a"]]
    // Explanation: For this input, the correct result is [["a"]].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolvePalindromePartitioning("");
    return true;
}

RUN_TESTS()
