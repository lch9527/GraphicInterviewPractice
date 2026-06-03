// NeetCode 150 NC067: Kth Largest Element in an Array
// Topic: Heap
// Difficulty: Medium
// Source: https://leetcode.com/problems/kth-largest-element-in-an-array/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the kth largest value in an unsorted array.

Examples:
    - Input: nums=[3,2,1,5,6,4], k=2 -> 5
      Explanation: For this input, the correct result is 5.
    - Input: nums=[3,2,3,1,2,4,5,5,6], k=4 -> 4
      Explanation: For this input, the correct result is 4.

Implement:
    int SolveKthLargestElementInAnArray(const std::vector<int>& nums, int k);
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
int SolveKthLargestElementInAnArray(const std::vector<int>& nums, int k) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: nums=[3,2,1,5,6,4], k=2 -> 5
    // Explanation: For this input, the correct result is 5.
    // Case 2: Input: nums=[3,2,3,1,2,4,5,5,6], k=4 -> 4
    // Explanation: For this input, the correct result is 4.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveKthLargestElementInAnArray({}, 0);
    return true;
}

RUN_TESTS()
