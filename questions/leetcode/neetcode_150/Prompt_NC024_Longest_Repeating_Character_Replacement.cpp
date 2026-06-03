// NeetCode 150 NC024: Longest Repeating Character Replacement
// Topic: Sliding Window
// Difficulty: Medium
// Source: https://leetcode.com/problems/longest-repeating-character-replacement/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    After replacing at most k characters, return the longest substring that can be made of one repeated character.

Examples:
    - Input: s="ABAB", k=2 -> 4
      Explanation: For this input, the correct result is 4.
    - Input: s="AABABBA", k=1 -> 4
      Explanation: For this input, the correct result is 4.

Implement:
    int SolveLongestRepeatingCharacterReplacement(const std::string& s, int k);
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
int SolveLongestRepeatingCharacterReplacement(const std::string& s, int k) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: s="ABAB", k=2 -> 4
    // Explanation: For this input, the correct result is 4.
    // Case 2: Input: s="AABABBA", k=1 -> 4
    // Explanation: For this input, the correct result is 4.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveLongestRepeatingCharacterReplacement("", 0);
    return true;
}

RUN_TESTS()
