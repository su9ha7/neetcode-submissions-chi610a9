#include <unordered_set>

class Solution {
private:
    std::unordered_set<int> cols;
    std::unordered_set<int> posDiag; // (row + col)
    std::unordered_set<int> negDiag; // (row - col)

    void backtrack(int row, int n, int& count) {
        // Base Case: All n queens placed successfully
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            // Collision check using O(1) sets
            if (cols.count(col) || posDiag.count(row + col) || negDiag.count(row - col)) {
                continue;
            }

            // Make Choice
            cols.insert(col);
            posDiag.insert(row + col);
            negDiag.insert(row - col);

            // Explore next row
            backtrack(row + 1, n, count);

            // Undo Choice (Backtrack)
            cols.erase(col);
            posDiag.erase(row + col);
            negDiag.erase(row - col);
        }
    }

public:
    int totalNQueens(int n) {
        int count = 0;
        backtrack(0, n, count);
        return count;
    }
};