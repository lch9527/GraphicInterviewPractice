// Tesla Q05: Number of Islands
/*
Description:
Count connected groups of land cells in a grid. Land connects horizontally and vertically.

Task:
Implement this function:
    int NumIslands(std::vector<std::string> grid);
*/

#include "MathTypes.h"
#include <string>
#include <vector>

void FloodFill(std::vector<std::string>& grid, int row, int col) {
    if (row < 0 || col < 0 || row >= static_cast<int>(grid.size()) ||
        col >= static_cast<int>(grid[row].size()) || grid[row][col] != '1') {
        return;
    }

    grid[row][col] = '0';
    FloodFill(grid, row + 1, col);
    FloodFill(grid, row - 1, col);
    FloodFill(grid, row, col + 1);
    FloodFill(grid, row, col - 1);
}

int NumIslands(std::vector<std::string> grid) {
    int count = 0;
    for (int row = 0; row < static_cast<int>(grid.size()); ++row) {
        for (int col = 0; col < static_cast<int>(grid[row].size()); ++col) {
            if (grid[row][col] == '1') {
                ++count;
                FloodFill(grid, row, col);
            }
        }
    }
    return count;
}

bool RunTests() {
    EXPECT_EQ_INT(NumIslands({"11110","11010","11000","00000"}), 1);
    EXPECT_EQ_INT(NumIslands({"11000","11000","00100","00011"}), 3);
    EXPECT_EQ_INT(NumIslands({}), 0);
    EXPECT_EQ_INT(NumIslands({"10101"}), 3);
    return true;
}

RUN_TESTS()

