#include <vector>
#include <string>
#include <unordered_set>

class Solution {
private:
    void backtrack(int start, const std::string& s, const std::unordered_set<std::string>& wordSet, 
                   std::vector<std::string>& currentPath, std::vector<std::string>& result) {
        // Base Case: Reached the end of string s successfully
        if (start == s.length()) {
            // Join path words with spaces
            std::string sentence = "";
            for (int i = 0; i < currentPath.size(); ++i) {
                sentence += currentPath[i];
                if (i < currentPath.size() - 1) {
                    sentence += " ";
                }
            }
            result.push_back(sentence);
            return;
        }

        // Try every possible substring starting from 'start'
        for (int end = start + 1; end <= s.length(); ++end) {
            std::string sub = s.substr(start, end - start);

            if (wordSet.count(sub)) {
                // Choice
                currentPath.push_back(sub);

                // Recurse
                backtrack(end, s, wordSet, currentPath, result);

                // Backtrack
                currentPath.pop_back();
            }
        }
    }

public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
        std::vector<std::string> result;
        std::vector<std::string> currentPath;

        backtrack(0, s, wordSet, currentPath, result);
        return result;
    }
};