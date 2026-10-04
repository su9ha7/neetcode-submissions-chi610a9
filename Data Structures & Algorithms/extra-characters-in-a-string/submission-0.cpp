#include <string>
#include <vector>
#include <algorithm>

struct TrieNode {
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
private:
    TrieNode* root;

    void insert(const std::string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isWord = true;
    }

public:
    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        root = new TrieNode();
        
        // 1. Build the Trie from the dictionary
        for (const std::string& word : dictionary) {
            insert(word);
        }

        int n = s.length();
        // dp[i] stores min extra characters for substring s[i...n-1]
        std::vector<int> dp(n + 1, 0);

        // 2. Fill DP table backwards
        for (int i = n - 1; i >= 0; i--) {
            // Option 1: Treat s[i] as an extra character
            dp[i] = 1 + dp[i + 1];

            // Option 2: Try matching words starting at index i using the Trie
            TrieNode* curr = root;
            for (int j = i; j < n; j++) {
                int index = s[j] - 'a';
                
                // If the path breaks in the Trie, no longer word can start at i
                if (!curr->children[index]) {
                    break;
                }
                
                curr = curr->children[index];
                
                // If a valid dictionary word ends at j, update dp[i]
                if (curr->isWord) {
                    dp[i] = std::min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};