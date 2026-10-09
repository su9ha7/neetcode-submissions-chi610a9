#include <vector>

class Solution {
private:
    void dfs(std::vector<std::vector<char>>& board, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();

        // Base case: Out of bounds or not an 'O'
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') {
            return;
        }

        // Mark this 'O' as safe/unsurrounded
        board[r][c] = 'T';

        // Traverse 4 directions
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

public:
    void solve(std::vector<std::vector<char>>& board) {
        if (board.empty()) return;

        int rows = board.size();
        int cols = board[0].size();

        // 1. Run DFS for 'O's on the top and bottom borders
        for (int c = 0; c < cols; ++c) {
            if (board[0][c] == 'O') dfs(board, 0, c);
            if (board[rows - 1][c] == 'O') dfs(board, rows - 1, c);
        }

        // 2. Run DFS for 'O's on the left and right borders
        for (int r = 0; r < rows; ++r) {
            if (board[r][0] == 'O') dfs(board, r, 0);
            if (board[r][cols - 1] == 'O') dfs(board, r, cols - 1);
        }

        // 3. Final Pass: Replace remaining 'O' with 'X', and 'T' back to 'O'
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X'; // Captured
                } else if (board[r][c] == 'T') {
                    board[r][c] = 'O'; // Safe
                }
            }
        }
    }
};