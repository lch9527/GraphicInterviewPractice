// NeetCode 150 NC066: K Closest Points to Origin
// Topic: Heap
// Difficulty: Medium
// Source: https://leetcode.com/problems/k-closest-points-to-origin/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the k points with smallest squared distance to the origin.

Examples:
    - Input: points=[[1,3],[-2,2]], k=1 -> [[-2,2]]
      Explanation: For this input, the correct result is [[-2,2]].
    - Input: [[3,3],[5,-1],[-2,4]], k=2 -> two closest points
      Explanation: For this input, the correct result is two closest points.

Implement:
    std::vector<std::vector<int>> SolveKClosestPointsToOrigin(const std::vector<std::vector<int>>& points, int k);
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
std::vector<std::vector<int>> SolveKClosestPointsToOrigin(const std::vector<std::vector<int>>& points, int k) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: points=[[1,3],[-2,2]], k=1 -> [[-2,2]]
    // Explanation: For this input, the correct result is [[-2,2]].
    // Case 2: Input: [[3,3],[5,-1],[-2,4]], k=2 -> two closest points
    // Explanation: For this input, the correct result is two closest points.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveKClosestPointsToOrigin({}, 0);
    return true;
}

RUN_TESTS()
