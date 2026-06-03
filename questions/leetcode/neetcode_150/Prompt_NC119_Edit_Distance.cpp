// NeetCode 150 NC119: Edit Distance
// Topic: Dynamic Programming
// Difficulty: Medium
// Source: https://leetcode.com/problems/edit-distance/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the minimum insertions, deletions, and replacements to convert one word to another.

Examples:
    - Input: word1="horse", word2="ros" -> 3
      Explanation: For this input, the correct result is 3.
    - Input: "intention", "execution" -> 5
      Explanation: For this input, the correct result is 5.

Implement:
    int SolveEditDistance(const std::string& word1, const std::string& word2);
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
int SolveEditDistance(const std::string& word1, const std::string& word2) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: word1="horse", word2="ros" -> 3
    // Explanation: For this input, the correct result is 3.
    // Case 2: Input: "intention", "execution" -> 5
    // Explanation: For this input, the correct result is 5.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveEditDistance("", "");
    return true;
}

RUN_TESTS()
