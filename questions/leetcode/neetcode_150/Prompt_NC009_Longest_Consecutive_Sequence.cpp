// NeetCode 150 NC009: Longest Consecutive Sequence
// Topic: Arrays & Hashing
// Difficulty: Medium
// Source: https://leetcode.com/problems/longest-consecutive-sequence/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Find the length of the longest run of consecutive integers in an unsorted array.

Examples:
    - Input: [100,4,200,1,3,2] -> 4
      Explanation: For this input, the correct result is 4.
    - Input: [0,3,7,2,5,8,4,6,0,1] -> 9
      Explanation: For this input, the correct result is 9.

Implement:
    int SolveLongestConsecutiveSequence(const std::vector<int>& nums);
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
int SolveLongestConsecutiveSequence(const std::vector<int>& nums) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [100,4,200,1,3,2] -> 4
    // Explanation: For this input, the correct result is 4.
    // Case 2: Input: [0,3,7,2,5,8,4,6,0,1] -> 9
    // Explanation: For this input, the correct result is 9.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveLongestConsecutiveSequence({});
    return true;
}

RUN_TESTS()
