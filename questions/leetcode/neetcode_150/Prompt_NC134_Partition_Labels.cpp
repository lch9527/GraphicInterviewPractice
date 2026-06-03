// NeetCode 150 NC134: Partition Labels
// Topic: Greedy
// Difficulty: Medium
// Source: https://leetcode.com/problems/partition-labels/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Partition a string so each character appears in at most one part and return part sizes.

Examples:
    - Input: "ababcbacadefegdehijhklij" -> [9,7,8]
      Explanation: For this input, the correct result is [9,7,8].
    - Input: "eccbbbbdec" -> [10]
      Explanation: For this input, the correct result is [10].

Implement:
    std::vector<int> SolvePartitionLabels(const std::string& s);
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
std::vector<int> SolvePartitionLabels(const std::string& s) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: "ababcbacadefegdehijhklij" -> [9,7,8]
    // Explanation: For this input, the correct result is [9,7,8].
    // Case 2: Input: "eccbbbbdec" -> [10]
    // Explanation: For this input, the correct result is [10].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolvePartitionLabels("");
    return true;
}

RUN_TESTS()
