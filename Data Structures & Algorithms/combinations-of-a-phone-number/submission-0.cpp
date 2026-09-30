#include <vector>
#include <string>

class Solution {
private:
    // Mapping digits to their corresponding telephone keypad letters
    const std::vector<std::string> pad = {
        "",     "",     "abc",  "def",  // 0, 1, 2, 3
        "ghi",  "jkl",  "mno",          // 4, 5, 6
        "pqrs", "tuv",  "wxyz"          // 7, 8, 9
    };

    void backtrack(int index, std::string& path, const std::string& digits, std::vector<std::string>& result) {
        // Base Case: We formed a string matching the length of input digits
        if (index == digits.length()) {
            result.push_back(path);
            return;
        }

        // Get letters mapped to the current digit (e.g., '2' -> '2' - '0' = 2 -> "abc")
        int digit = digits[index] - '0';
        const std::string& letters = pad[digit];

        // Loop through each possible letter choice for this digit
        for (char c : letters) {
            // Choice
            path.push_back(c);

            // Explore next digit
            backtrack(index + 1, path, digits, result);

            // Backtrack (undo choice)
            path.pop_back();
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.empty()) {
            return result;
        }

        std::string path = "";
        backtrack(0, path, digits, result);
        return result;
    }
};
