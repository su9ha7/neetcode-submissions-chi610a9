#include <vector>
#include <string>

class Solution {
private:
    void backtrack(int open, int close, int n, std::string& path, std::vector<std::string>& result) {
        // Base Case: complete valid parenthesis string formed
        if (open == n && close == n) {
            result.push_back(path);
            return;
        }

        // Choice 1: Add an opening parenthesis '('
        if (open < n) {
            path.push_back('(');
            backtrack(open + 1, close, n, path, result);
            path.pop_back(); // Undo choice
        }

        // Choice 2: Add a closing parenthesis ')'
        if (close < open) {
            path.push_back(')');
            backtrack(open, close + 1, n, path, result);
            path.pop_back(); // Undo choice
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string path = "";
        backtrack(0, 0, n, path, result);
        return result;
    }
};
