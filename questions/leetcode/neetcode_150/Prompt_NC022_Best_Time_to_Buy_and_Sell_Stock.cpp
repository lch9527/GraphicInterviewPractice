// NeetCode 150 NC022: Best Time to Buy and Sell Stock
// Topic: Sliding Window
// Difficulty: Easy
// Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the maximum profit from one buy followed by one sell.

Examples:
    - Input: [7,1,5,3,6,4] -> 5
      Explanation: For this input, the correct result is 5.
    - Input: [7,6,4,3,1] -> 0
      Explanation: For this input, the correct result is 0.

Implement:
    int SolveBestTimeToBuyAndSellStock(const std::vector<int>& prices);
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
int SolveBestTimeToBuyAndSellStock(const std::vector<int>& prices) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [7,1,5,3,6,4] -> 5
    // Explanation: For this input, the correct result is 5.
    // Case 2: Input: [7,6,4,3,1] -> 0
    // Explanation: For this input, the correct result is 0.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveBestTimeToBuyAndSellStock({});
    return true;
}

RUN_TESTS()
