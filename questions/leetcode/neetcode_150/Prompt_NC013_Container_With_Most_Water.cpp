// NeetCode 150 NC013: Container With Most Water
// Topic: Two Pointers
// Difficulty: Medium
// Source: https://leetcode.com/problems/container-with-most-water/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Find the maximum water area formed by two vertical lines and the x-axis.

Examples:
    - Input: [1,8,6,2,5,4,8,3,7] -> 49
      Explanation: For this input, the correct result is 49.
    - Input: [1,1] -> 1
      Explanation: For this input, the correct result is 1.

Implement:
    int SolveContainerWithMostWater(const std::vector<int>& height);
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
int SolveContainerWithMostWater(const std::vector<int>& height) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [1,8,6,2,5,4,8,3,7] -> 49
    // Explanation: For this input, the correct result is 49.
    // Case 2: Input: [1,1] -> 1
    // Explanation: For this input, the correct result is 1.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveContainerWithMostWater({});
    return true;
}

RUN_TESTS()
