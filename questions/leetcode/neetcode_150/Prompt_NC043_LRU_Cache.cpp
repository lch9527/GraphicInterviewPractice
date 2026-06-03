// NeetCode 150 NC043: LRU Cache
// Topic: Linked List
// Difficulty: Medium
// Source: https://leetcode.com/problems/lru-cache/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Design a cache with get and put in O(1), evicting least-recently-used entries.

Examples:
    - Operations: put(1,1), put(2,2), get(1) -> 1, put(3,3), get(2) -> -1
      Explanation: After performing the listed operations, the observed result should be 1, put(3,3), get(2) -> -1.
    - Capacity 1 evicts on every new key

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
class LRUCache { public: explicit LRUCache(int capacity) { (void)capacity; } int Get(int key) { (void)key; return -1; } void Put(int key, int value) { (void)key; (void)value; } };

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Operations: put(1,1), put(2,2), get(1) -> 1, put(3,3), get(2) -> -1
    // Explanation: After performing the listed operations, the observed result should be 1, put(3,3), get(2) -> -1.
    // Case 2: Capacity 1 evicts on every new key
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    LRUCache value(1); value.Put(1, 1); (void)value.Get(1);
    return true;
}

RUN_TESTS()
