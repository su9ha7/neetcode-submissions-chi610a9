#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        std::queue<std::pair<int, int>> q;
        int freshCount = 0;
        int minutes = 0;

        // 1. Initialize queue with all rotten oranges and count fresh ones
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }

        // Base case: No fresh oranges to begin with
        if (freshCount == 0) return 0;

        std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // 2. Process multi-source BFS level-by-level
        while (!q.empty() && freshCount > 0) {
            int qSize = q.size(); // Number of rotten oranges in current minute batch

            for (int i = 0; i < qSize; ++i) {
                auto [r, c] = q.front();
                q.pop();

                for (const auto& dir : directions) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    // If neighbor is in bounds and is a fresh orange
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Make it rotten
                        freshCount--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++; // One minute passes after rotting the current layer
        }

        return freshCount == 0 ? minutes : -1;
    }
};