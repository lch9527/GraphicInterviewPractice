// Run from this file directory:
//   mkdir -p ../../questions_artifacts/tesla && g++ -std=c++17 -I../../include Q05_Number_of_Islands.cpp -o ../../questions_artifacts/tesla/tesla_q05 && ../../questions_artifacts/tesla/tesla_q05

// Tesla Q05: Number of Islands
/*
Description:
Given a 2D grid of strings where '1' is land and '0' is water, count how many
separate islands exist.

An island is a group of land cells connected horizontally or vertically.
Diagonal touching does not connect islands.

Examples:
    {"11110",
     "11010",
     "11000",
     "00000"} -> 1
        All land cells are connected into one island.

    {"11000",
     "11000",
     "00100",
     "00011"} -> 3
        There are three separate land groups.

    {"10101"} -> 3
        Each '1' is separated by water, so each is its own island.

Edge cases:
    Empty input returns 0.
    You may modify the grid copy passed into the function.

Task:
Implement this function:
    int NumIslands(std::vector<std::string> grid);
*/

#include "MathTypes.h"
#include <string>
#include <vector>

void FloodFill(std::vector<std::string>& grid, int row, int col) {
    // TODO: implement if you choose a flood-fill solution.
    (void)grid;
    (void)row;
    (void)col;
}

int NumIslands(std::vector<std::string> grid) {
    // TODO: implement.
    (void)grid;
    return 0;
}

bool RunTests() {
    EXPECT_EQ_INT(NumIslands({"11110","11010","11000","00000"}), 1);
    EXPECT_EQ_INT(NumIslands({"11000","11000","00100","00011"}), 3);
    EXPECT_EQ_INT(NumIslands({}), 0);
    EXPECT_EQ_INT(NumIslands({"10101"}), 3);
    return true;
}

RUN_TESTS()

