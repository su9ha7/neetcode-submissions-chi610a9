#include <vector>
#include <string>

class Solution {
private:
    // Helper function to check if a substring s[left...right] is a palindrome
    bool isPalindrome(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void backtrack(int start, std::string& s, std::vector<std::string>& path, std::vector<std::vector<std::string>>& result) {
        // Base Case: We reached the end of the string, so path contains a valid partition
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            // Only proceed if s[start...i] is a valid palindrome
            if (isPalindrome(s, start, i)) {
                // Choice: add s[start...i] to current partition
                path.push_back(s.substr(start, i - start + 1));

                // Recurse for the remainder of the string starting at i + 1
                backtrack(i + 1, s, path, result);

                // Undo Choice (Backtrack)
                path.pop_back();
            }
        }
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> path;

        backtrack(0, s, path, result);
        return result;
    }
};