// NeetCode 150 NC127: Minimum Interval to Include Each Query
// Topic: Intervals
// Difficulty: Hard
// Source: https://leetcode.com/problems/minimum-interval-to-include-each-query/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    For each query, return the size of the smallest interval that contains it, or -1.

Examples:
    - Input: intervals=[[1,4],[2,4],[3,6],[4,4]], queries=[2,3,4,5] -> [3,3,1,4]
      Explanation: For this input, the correct result is [3,3,1,4].
    - Query outside all intervals -> -1
      Explanation: This example should produce -1.

Implement:
    std::vector<int> SolveMinimumIntervalToIncludeEachQuery(std::vector<std::vector<int>> intervals, std::vector<int> queries);
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
std::vector<int> SolveMinimumIntervalToIncludeEachQuery(std::vector<std::vector<int>> intervals, std::vector<int> queries) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: intervals=[[1,4],[2,4],[3,6],[4,4]], queries=[2,3,4,5] -> [3,3,1,4]
    // Explanation: For this input, the correct result is [3,3,1,4].
    // Case 2: Query outside all intervals -> -1
    // Explanation: This example should produce -1.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveMinimumIntervalToIncludeEachQuery({}, {});
    return true;
}

RUN_TESTS()
