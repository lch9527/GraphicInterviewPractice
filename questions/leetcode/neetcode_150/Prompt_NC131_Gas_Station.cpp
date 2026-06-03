// NeetCode 150 NC131: Gas Station
// Topic: Greedy
// Difficulty: Medium
// Source: https://leetcode.com/problems/gas-station/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Return the starting gas station index that completes the circuit, or -1.

Examples:
    - Input: gas=[1,2,3,4,5], cost=[3,4,5,1,2] -> 3
      Explanation: For this input, the correct result is 3.
    - Input: gas=[2,3,4], cost=[3,4,3] -> -1
      Explanation: For this input, the correct result is -1.

Implement:
    int SolveGasStation(const std::vector<int>& gas, const std::vector<int>& cost);
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
int SolveGasStation(const std::vector<int>& gas, const std::vector<int>& cost) {
    // TODO: implement.
    return 0;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: gas=[1,2,3,4,5], cost=[3,4,5,1,2] -> 3
    // Explanation: For this input, the correct result is 3.
    // Case 2: Input: gas=[2,3,4], cost=[3,4,3] -> -1
    // Explanation: For this input, the correct result is -1.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveGasStation({}, {});
    return true;
}

RUN_TESTS()
