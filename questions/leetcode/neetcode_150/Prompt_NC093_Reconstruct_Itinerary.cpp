// NeetCode 150 NC093: Reconstruct Itinerary
// Topic: Graphs
// Difficulty: Hard
// Source: https://leetcode.com/problems/reconstruct-itinerary/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Use all airline tickets once to build the lexicographically smallest itinerary from JFK.

Examples:
    - Input: [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]] -> ["JFK","MUC","LHR","SFO","SJC"]
      Explanation: For this input, the correct result is ["JFK","MUC","LHR","SFO","SJC"].
    - Multiple choices choose lexical order

Implement:
    std::vector<std::string> SolveReconstructItinerary(const std::vector<std::vector<std::string>>& tickets);
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
std::vector<std::string> SolveReconstructItinerary(const std::vector<std::vector<std::string>>& tickets) {
    // TODO: implement.
    return {};
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]] -> ["JFK","MUC","LHR","SFO","SJC"]
    // Explanation: For this input, the correct result is ["JFK","MUC","LHR","SFO","SJC"].
    // Case 2: Multiple choices choose lexical order
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveReconstructItinerary("");
    return true;
}

RUN_TESTS()
