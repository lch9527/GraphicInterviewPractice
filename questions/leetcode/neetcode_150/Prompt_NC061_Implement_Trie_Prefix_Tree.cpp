// NeetCode 150 NC061: Implement Trie Prefix Tree
// Topic: Tries
// Difficulty: Medium
// Source: https://leetcode.com/problems/implement-trie-prefix-tree/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Design a trie supporting insert, exact word search, and prefix search.

Examples:
    - Operations: insert("apple"), search("apple") -> true, search("app") -> false, startsWith("app") -> true
      Explanation: After performing the listed operations, the observed result should be true, search("app") -> false, startsWith("app") -> true.
    - insert("app"), search("app") -> true
      Explanation: This example should produce true.

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
class Trie { public: void Insert(const std::string& word) { (void)word; } bool Search(const std::string& word) const { (void)word; return false; } bool StartsWith(const std::string& prefix) const { (void)prefix; return false; } };

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Operations: insert("apple"), search("apple") -> true, search("app") -> false, startsWith("app") -> true
    // Explanation: After performing the listed operations, the observed result should be true, search("app") -> false, startsWith("app") -> true.
    // Case 2: insert("app"), search("app") -> true
    // Explanation: This example should produce true.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    Trie value; value.Insert("app"); (void)value.Search("app"); (void)value.StartsWith("a");
    return true;
}

RUN_TESTS()
