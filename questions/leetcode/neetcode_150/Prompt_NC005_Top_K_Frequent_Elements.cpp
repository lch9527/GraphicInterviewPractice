// NeetCode 150 NC005: Top K Frequent Elements
// Topic: Arrays & Hashing
// Difficulty: Medium
// Source: https://leetcode.com/problems/top-k-frequent-elements/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the k values that occur most often in an integer array.

Examples:
    - Input: nums=[1,1,1,2,2,3], k=2 -> [1,2]
      Explanation: For this input, the correct result is [1,2].
    - Input: nums=[1], k=1 -> [1]
      Explanation: For this input, the correct result is [1].

Implement:
    std::vector<int> SolveTopKFrequent(const std::vector<int>& nums, int k);
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
std::vector<int> SolveTopKFrequent(const std::vector<int>& nums, int k) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: nums=[1,1,1,2,2,3], k=2 -> [1,2]
    // Explanation: For this input, the correct result is [1,2].
    // Case 2: Input: nums=[1], k=1 -> [1]
    // Explanation: For this input, the correct result is [1].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveTopKFrequent({}, 0);
    return true;
}

RUN_TESTS()
