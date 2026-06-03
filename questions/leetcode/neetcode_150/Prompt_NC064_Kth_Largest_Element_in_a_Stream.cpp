// NeetCode 150 NC064: Kth Largest Element in a Stream
// Topic: Heap
// Difficulty: Easy
// Source: https://leetcode.com/problems/kth-largest-element-in-a-stream/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Maintain the kth largest value after each inserted stream value.

Examples:
    - Operations: k=3, nums=[4,5,8,2], add(3)->4, add(5)->5, add(10)->5
      Explanation: After each add, return the current 3rd largest stream value.
    - add(9)->8
      Explanation: After adding 9, the 3rd largest value becomes 8.

Implement:
    Implement the class shown below.
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
class KthLargest { public: KthLargest(int k, const std::vector<int>& nums) { (void)k; (void)nums; } int Add(int val) { (void)val; return 0; } };

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Operations: k=3, nums=[4,5,8,2], add(3)->4, add(5)->5, add(10)->5
    // Explanation: After each add, return the current 3rd largest stream value.
    // Case 2: add(9)->8
    // Explanation: After adding 9, the 3rd largest value becomes 8.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    KthLargest value(1, {}); (void)value.Add(0);
    return true;
}

RUN_TESTS()
