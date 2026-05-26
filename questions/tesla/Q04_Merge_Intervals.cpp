// Run from this file directory:
//   mkdir -p ../../questions_artifacts/tesla && g++ -std=c++17 -I../../include Q04_Merge_Intervals.cpp -o ../../questions_artifacts/tesla/tesla_q04 && ../../questions_artifacts/tesla/tesla_q04

// Tesla Q04: Merge Intervals
/*
Description:
Given a list of closed intervals [start, end], merge every overlapping interval
and return the compact list of non-overlapping intervals.

Closed intervals include both endpoints, so [1,4] and [4,5] overlap and merge
into [1,5].

Examples:
    {{1,3},{2,6},{8,10},{15,18}} -> {{1,6},{8,10},{15,18}}
        [1,3] overlaps [2,6], so they become [1,6].

    {{1,4},{4,5}} -> {{1,5}}
        The intervals touch at 4, and because they are closed, they merge.

    {{5,7},{1,2},{2,4}} -> {{1,4},{5,7}}
        Input may be unsorted, so ordering by start is usually the first step.

Edge cases:
    Empty input returns an empty vector.
    Fully contained intervals should not create extra output intervals.

Task:
Implement this function:
    std::vector<Interval> MergeIntervals(std::vector<Interval> intervals);
*/

#include "MathTypes.h"
#include <vector>
#include <algorithm>

struct Interval {
    int start = 0;
    int end = 0;
};

bool SameIntervals(const std::vector<Interval>& a, const std::vector<Interval>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i].start != b[i].start || a[i].end != b[i].end) return false;
    }
    return true;
}

std::vector<Interval> MergeIntervals(std::vector<Interval> intervals) {
    // TODO: implement.
    (void)intervals;
    return {};
}

bool RunTests() {
    EXPECT_TRUE(SameIntervals(MergeIntervals({{1,3},{2,6},{8,10},{15,18}}), {{1,6},{8,10},{15,18}}));
    EXPECT_TRUE(SameIntervals(MergeIntervals({{1,4},{4,5}}), {{1,5}}));
    EXPECT_TRUE(SameIntervals(MergeIntervals({{5,7},{1,2},{2,4}}), {{1,4},{5,7}}));
    return true;
}

RUN_TESTS()

