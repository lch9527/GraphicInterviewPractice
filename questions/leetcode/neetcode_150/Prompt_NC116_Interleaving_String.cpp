// NeetCode 150 NC116: Interleaving String
// Topic: Dynamic Programming
// Difficulty: Medium
// Source: https://leetcode.com/problems/interleaving-string/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return whether s3 is formed by interleaving s1 and s2 while preserving order.

Examples:
    - Input: s1="aabcc", s2="dbbca", s3="aadbbcbcac" -> true
      Explanation: For this input, the correct result is true.
    - s3="aadbbbaccc" -> false
      Explanation: This example should produce false.

Implement:
    bool SolveInterleavingString(const std::string& s1, const std::string& s2, const std::string& s3);
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
bool SolveInterleavingString(const std::string& s1, const std::string& s2, const std::string& s3) {
    // TODO: implement.
    return false;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: s1="aabcc", s2="dbbca", s3="aadbbcbcac" -> true
    // Explanation: For this input, the correct result is true.
    // Case 2: s3="aadbbbaccc" -> false
    // Explanation: This example should produce false.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveInterleavingString("", "", "");
    return true;
}

RUN_TESTS()
