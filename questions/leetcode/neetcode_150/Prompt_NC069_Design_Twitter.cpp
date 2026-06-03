// NeetCode 150 NC069: Design Twitter
// Topic: Heap
// Difficulty: Medium
// Source: https://leetcode.com/problems/design-twitter/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Design a mini Twitter supporting postTweet, follow, unfollow, and getNewsFeed.

Examples:
    - Operations: postTweet(1,5), getNewsFeed(1) -> [5]
      Explanation: After performing the listed operations, the observed result should be [5].
    - follow(1,2), postTweet(2,6), getNewsFeed(1) -> [6,5]
      Explanation: This example should produce [6,5].

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
class Twitter { public: void PostTweet(int userId, int tweetId) { (void)userId; (void)tweetId; } std::vector<int> GetNewsFeed(int userId) { (void)userId; return {}; } void Follow(int followerId, int followeeId) { (void)followerId; (void)followeeId; } void Unfollow(int followerId, int followeeId) { (void)followerId; (void)followeeId; } };

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Operations: postTweet(1,5), getNewsFeed(1) -> [5]
    // Explanation: After performing the listed operations, the observed result should be [5].
    // Case 2: follow(1,2), postTweet(2,6), getNewsFeed(1) -> [6,5]
    // Explanation: This example should produce [6,5].
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    Twitter value; value.PostTweet(1, 1); (void)value.GetNewsFeed(1);
    return true;
}

RUN_TESTS()
