// NeetCode 150 NC123: Merge Intervals
// Topic: Intervals
// Difficulty: Medium
// Source: https://leetcode.com/problems/merge-intervals/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Merge all overlapping closed intervals.

Examples:
    - Input: [[1,3],[2,6],[8,10],[15,18]] -> [[1,6],[8,10],[15,18]]
      Explanation: For this input, the correct result is [[1,6],[8,10],[15,18]].
    - Input: [[1,4],[4,5]] -> [[1,5]]
      Explanation: For this input, the correct result is [[1,5]].

Implement:
    std::vector<std::vector<int>> SolveMergeIntervals(std::vector<std::vector<int>> intervals);
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
std::vector<std::vector<int>> SolveMergeIntervals(std::vector<std::vector<int>> intervals) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [[1,3],[2,6],[8,10],[15,18]] -> [[1,6],[8,10],[15,18]]
    // Explanation: For this input, the correct result is [[1,6],[8,10],[15,18]].
    // Case 2: Input: [[1,4],[4,5]] -> [[1,5]]
    // Explanation: For this input, the correct result is [[1,5]].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveMergeIntervals({});
    return true;
}

RUN_TESTS()
