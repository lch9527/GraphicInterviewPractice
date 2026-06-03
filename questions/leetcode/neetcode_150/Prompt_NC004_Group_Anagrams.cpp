// NeetCode 150 NC004: Group Anagrams
// Topic: Arrays & Hashing
// Difficulty: Medium
// Source: https://leetcode.com/problems/group-anagrams/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Group strings that are anagrams of each other.

Examples:
    - Input: ["eat","tea","tan","ate","nat","bat"] -> groups ["bat"], ["nat","tan"], ["ate","eat","tea"]
      Explanation: For this input, the correct result is groups ["bat"], ["nat","tan"], ["ate","eat","tea"].
    - Input: [""] -> [[""]]
      Explanation: For this input, the correct result is [[""]].

Implement:
    std::vector<std::vector<std::string>> SolveGroupAnagrams(const std::vector<std::string>& strs);
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
std::vector<std::vector<std::string>> SolveGroupAnagrams(const std::vector<std::string>& strs) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: ["eat","tea","tan","ate","nat","bat"] -> groups ["bat"], ["nat","tan"], ["ate","eat","tea"]
    // Explanation: For this input, the correct result is groups ["bat"], ["nat","tan"], ["ate","eat","tea"].
    // Case 2: Input: [""] -> [[""]]
    // Explanation: For this input, the correct result is [[""]].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveGroupAnagrams("");
    return true;
}

RUN_TESTS()
