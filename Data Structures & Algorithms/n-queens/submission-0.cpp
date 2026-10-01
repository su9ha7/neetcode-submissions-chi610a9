#include <vector>
#include <string>
#include <unordered_set>

class Solution {
private:
    std::unordered_set<int> cols;
    std::unordered_set<int> posDiag; // (row + col)
    std::unordered_set<int> negDiag; // (row - col)

    void backtrack(int row, int n, std::vector<std::string>& board, std::vector<std::vector<std::string>>& result) {
        // Base Case: Placed queens in all n rows successfully
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            // Check if placing a queen at (row, col) causes a collision
            if (cols.count(col) || posDiag.count(row + col) || negDiag.count(row - col)) {
                continue;
            }

            // Make Choice
            cols.insert(col);
            posDiag.insert(row + col);
            negDiag.insert(row - col);
            board[row][col] = 'Q';

            // Explore next row
            backtrack(row + 1, n, board, result);

            // Undo Choice (Backtrack)
            cols.erase(col);
            posDiag.erase(row + col);
            negDiag.erase(row - col);
            board[row][col] = '.';
        }
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        // Initialize an empty board filled with '.'
        std::vector<std::string> board(n, std::string(n, '.'));

        backtrack(0, n, board, result);
        return result;
    }
};
