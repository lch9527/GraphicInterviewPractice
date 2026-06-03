// NeetCode 150 NC125: Meeting Rooms
// Topic: Intervals
// Difficulty: Easy
// Source: https://leetcode.com/problems/meeting-rooms/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return whether a person can attend all meetings without overlapping intervals.

Examples:
    - Input: [[0,30],[5,10],[15,20]] -> false
      Explanation: For this input, the correct result is false.
    - Input: [[7,10],[2,4]] -> true
      Explanation: For this input, the correct result is true.

Implement:
    bool SolveMeetingRooms(std::vector<std::vector<int>> intervals);
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
bool SolveMeetingRooms(std::vector<std::vector<int>> intervals) {
    // TODO: implement.
    return false;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [[0,30],[5,10],[15,20]] -> false
    // Explanation: For this input, the correct result is false.
    // Case 2: Input: [[7,10],[2,4]] -> true
    // Explanation: For this input, the correct result is true.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveMeetingRooms({});
    return true;
}

RUN_TESTS()
