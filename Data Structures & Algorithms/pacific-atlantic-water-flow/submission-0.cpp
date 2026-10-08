class Solution {
public:

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {

        visited[r][c] = true;

        int rows = heights.size();
        int cols = heights[0].size();

        vector<pair<int,int>> directions = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        for (auto dir : directions) {

            int nr = r + dir.first;
            int nc = c + dir.second;

            // Check if inside grid
            if (nr < 0 || nr >= rows ||
                nc < 0 || nc >= cols)
                continue;

            // Already visited
            if (visited[nr][nc])
                continue;

            // Reverse flow condition
            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, heights, visited);
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        // Cells reachable from Pacific
        vector<vector<bool>> pacific(
            rows, vector<bool>(cols, false)
        );

        // Cells reachable from Atlantic
        vector<vector<bool>> atlantic(
            rows, vector<bool>(cols, false)
        );


        // Pacific: top row
        for (int c = 0; c < cols; c++) {
            dfs(0, c, heights, pacific);
        }

        // Pacific: left column
        for (int r = 0; r < rows; r++) {
            dfs(r, 0, heights, pacific);
        }


        // Atlantic: bottom row
        for (int c = 0; c < cols; c++) {
            dfs(rows - 1, c, heights, atlantic);
        }

        // Atlantic: right column
        for (int r = 0; r < rows; r++) {
            dfs(r, cols - 1, heights, atlantic);
        }


        // Find cells reachable from BOTH oceans
        vector<vector<int>> result;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
