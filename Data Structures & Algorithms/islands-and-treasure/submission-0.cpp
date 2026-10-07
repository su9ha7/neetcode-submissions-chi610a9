#include <vector>
#include <queue>

class Solution {
public:
    void islandsAndTreasure(std::vector<std::vector<int>>& grid) {
        if (grid.empty()) return;

        int rows = grid.size();
        int cols = grid[0].size();
        std::queue<std::pair<int, int>> q;

        // 1. Add all treasure chests (0s) to the queue
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        // Direction vectors for moving Down, Up, Right, Left
        std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // 2. Perform Multi-Source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (const auto& dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // If neighbor is within bounds AND is an unvisited land cell (INF)
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 2147483647) {
                    grid[nr][nc] = grid[r][c] + 1; // Distance is current distance + 1
                    q.push({nr, nc}); // Push to queue for further expansion
                }
            }
        }
    }
};