#include <vector>
#include <string>

class Solution {
private:
    bool backtrack(int r, int c, int index, std::vector<std::vector<char>>& board, const std::string& word) {
        // Base Case 1: All characters in 'word' matched!
        if (index == word.length()) {
            return true;
        }

        // Base Case 2: Out of bounds OR character mismatch OR cell already visited ('#')
        int rows = board.size();
        int cols = board[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index]) {
            return false;
        }

        // Step 1: Mark cell as visited in-place
        char temp = board[r][c];
        board[r][c] = '#';

        // Step 2: Explore all 4 adjacent directions (Up, Down, Left, Right)
        bool found = backtrack(r + 1, c, index + 1, board, word) ||
                     backtrack(r - 1, c, index + 1, board, word) ||
                     backtrack(r, c + 1, index + 1, board, word) ||
                     backtrack(r, c - 1, index + 1, board, word);

        // Step 3: Undo Choice (Backtrack by restoring original character)
        board[r][c] = temp;

        return found;
    }

public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // If starting letter matches, trigger DFS/backtracking
                if (board[r][c] == word[0] && backtrack(r, c, 0, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};