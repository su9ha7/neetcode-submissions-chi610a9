#include <vector>
#include <algorithm>

class Solution {
private:
    int dfs(std::vector<std::vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Base case: out of bounds or water (0)
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
            return 0;
        }

        // Sink the current cell so it's not visited again
        grid[r][c] = 0;

        // Count this cell (1) + all connected land cells in 4 directions
        return 1 + dfs(grid, r + 1, c)
                 + dfs(grid, r - 1, c)
                 + dfs(grid, r, c + 1)
                 + dfs(grid, r, c - 1);
    }

public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    int currentArea = dfs(grid, r, c);
                    maxArea = std::max(maxArea, currentArea);
                }
            }
        }

        return maxArea;
    }
};