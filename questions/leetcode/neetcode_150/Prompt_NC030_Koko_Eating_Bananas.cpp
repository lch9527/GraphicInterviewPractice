// NeetCode 150 NC030: Koko Eating Bananas
// Topic: Binary Search
// Difficulty: Medium
// Source: https://leetcode.com/problems/koko-eating-bananas/
// CoderPad-style prompt file. Implement the TODO function or class, then run tests.

/*
Description:
    Find the minimum eating speed that lets Koko finish all piles within h hours.

Examples:
    - Input: piles=[3,6,7,11], h=8 -> 4
      Explanation: For this input, the correct result is 4.
    - Input: piles=[30,11,23,4,20], h=5 -> 30
      Explanation: For this input, the correct result is 30.

Implement:
    int SolveKokoEatingBananas(const std::vector<int>& piles, int h);
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

 bool isabletoeat(const std::vector<int>& piles, int rate, int h) {
        long long time = 0;

        for (int pile : piles) {
            time += (pile + rate - 1) / rate;

            if (time > h) {
                return false;
            }
        }

        return time <= h;
    }

int SolveKokoEatingBananas(const std::vector<int>& piles, int h) {
     int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isabletoeat(piles, mid, h)) {
                ans = mid;
                r = mid - 1; // try smaller speed
            } else {
                l = mid + 1; // need bigger speed
            }
        }

        return ans;
}

bool RunTests() {
    // Example test cases from the prompt:
    // Case 1: Input: piles=[3,6,7,11], h=8 -> 4
    // Explanation: For this input, the correct result is 4.
    // Case 2: Input: piles=[30,11,23,4,20], h=5 -> 30
    // Explanation: For this input, the correct result is 30.
    // Keep these comments as the expected behavior, then replace the smoke call below with EXPECT_* assertions as you implement.
    (void)SolveKokoEatingBananas({}, 0);
    return true;
}

RUN_TESTS()
