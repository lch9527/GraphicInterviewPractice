// Tesla Q04: Merge Intervals
/*
Description:
Merge every overlapping closed interval and return the compact interval list.

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
    if (intervals.empty()) return {};

    std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        if (a.start != b.start) return a.start < b.start;
        return a.end < b.end;
    });

    std::vector<Interval> merged;
    merged.push_back(intervals.front());
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i].start <= merged.back().end) {
            merged.back().end = std::max(merged.back().end, intervals[i].end);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}

bool RunTests() {
    EXPECT_TRUE(SameIntervals(MergeIntervals({{1,3},{2,6},{8,10},{15,18}}), {{1,6},{8,10},{15,18}}));
    EXPECT_TRUE(SameIntervals(MergeIntervals({{1,4},{4,5}}), {{1,5}}));
    EXPECT_TRUE(SameIntervals(MergeIntervals({{5,7},{1,2},{2,4}}), {{1,4},{5,7}}));
    return true;
}

RUN_TESTS()

