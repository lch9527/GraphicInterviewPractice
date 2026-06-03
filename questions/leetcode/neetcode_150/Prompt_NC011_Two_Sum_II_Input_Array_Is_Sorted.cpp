// NeetCode 150 NC011: Two Sum II Input Array Is Sorted
// Topic: Two Pointers
// Difficulty: Medium
// Source: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Given a sorted 1-indexed array, return two indices whose values sum to the target.

Examples:
    - Input: numbers=[2,7,11,15], target=9 -> [1,2]
      Explanation: For this input, the correct result is [1,2].
    - Input: numbers=[2,3,4], target=6 -> [1,3]
      Explanation: For this input, the correct result is [1,3].

Implement:
    std::vector<int> SolveTwoSumIIInputArrayIsSorted(const std::vector<int>& numbers, int target);
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
std::vector<int> SolveTwoSumIIInputArrayIsSorted(const std::vector<int>& numbers, int target) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: numbers=[2,7,11,15], target=9 -> [1,2]
    // Explanation: For this input, the correct result is [1,2].
    // Case 2: Input: numbers=[2,3,4], target=6 -> [1,3]
    // Explanation: For this input, the correct result is [1,3].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveTwoSumIIInputArrayIsSorted({}, 0);
    return true;
}

RUN_TESTS()
