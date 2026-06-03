// NeetCode 150 NC088: Course Schedule II
// Topic: Graphs
// Difficulty: Medium
// Source: https://leetcode.com/problems/course-schedule-ii/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return one valid course order, or empty if impossible.

Examples:
    - Input: numCourses=2, prerequisites=[[1,0]] -> [0,1]
      Explanation: For this input, the correct result is [0,1].
    - Input: cycle -> []
      Explanation: For this input, the correct result is [].

Implement:
    std::vector<int> SolveCourseScheduleII(int numCourses, const std::vector<std::vector<int>>& prerequisites);
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
std::vector<int> SolveCourseScheduleII(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: numCourses=2, prerequisites=[[1,0]] -> [0,1]
    // Explanation: For this input, the correct result is [0,1].
    // Case 2: Input: cycle -> []
    // Explanation: For this input, the correct result is [].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveCourseScheduleII(0, {});
    return true;
}

RUN_TESTS()
