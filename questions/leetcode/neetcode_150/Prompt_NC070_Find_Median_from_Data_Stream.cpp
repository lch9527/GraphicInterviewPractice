// NeetCode 150 NC070: Find Median from Data Stream
// Topic: Heap
// Difficulty: Hard
// Source: https://leetcode.com/problems/find-median-from-data-stream/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Design a structure that adds numbers and returns the current median.

Examples:
    - Operations: addNum(1), addNum(2), findMedian() -> 1.5
      Explanation: After performing the listed operations, the observed result should be 1.5.
    - addNum(3), findMedian() -> 2
      Explanation: This example should produce 2.

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
class MedianFinder { public: void AddNum(int num) { (void)num; } double FindMedian() const { return 0.0; } };

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Operations: addNum(1), addNum(2), findMedian() -> 1.5
    // Explanation: After performing the listed operations, the observed result should be 1.5.
    // Case 2: addNum(3), findMedian() -> 2
    // Explanation: This example should produce 2.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    MedianFinder value; value.AddNum(1); (void)value.FindMedian();
    return true;
}

RUN_TESTS()
