// NeetCode 150 NC078: Letter Combinations of a Phone Number
// Topic: Backtracking
// Difficulty: Medium
// Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return all letter combinations represented by digits 2 through 9 on a phone keypad.

Examples:
    - Input: "23" -> ["ad","ae","af","bd","be","bf","cd","ce","cf"]
      Explanation: For this input, the correct result is ["ad","ae","af","bd","be","bf","cd","ce","cf"].
    - Input: "" -> []
      Explanation: For this input, the correct result is [].

Implement:
    std::vector<std::string> SolveLetterCombinationsOfAPhoneNumber(const std::string& digits);
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
std::vector<std::string> SolveLetterCombinationsOfAPhoneNumber(const std::string& digits) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: "23" -> ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    // Explanation: For this input, the correct result is ["ad","ae","af","bd","be","bf","cd","ce","cf"].
    // Case 2: Input: "" -> []
    // Explanation: For this input, the correct result is [].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveLetterCombinationsOfAPhoneNumber("");
    return true;
}

RUN_TESTS()
