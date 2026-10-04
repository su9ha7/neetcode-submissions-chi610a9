#include <string>
#include <vector>

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

class WordDictionary {
private:
    TrieNode* root;

    // Helper function for recursive DFS search
    bool searchInNode(const std::string& word, int index, TrieNode* curr) {
        if (!curr) return false;
        if (index == word.length()) return curr->isWord;

        char c = word[index];

        if (c == '.') {
            // Wildcard match: try all 26 possible branches
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] && searchInNode(word, index + 1, curr->children[i])) {
                    return true;
                }
            }
            return false;
        } else {
            // Standard letter match
            int childIndex = c - 'a';
            if (!curr->children[childIndex]) return false;
            return searchInNode(word, index + 1, curr->children[childIndex]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(std::string word) {
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
    
    bool search(std::string word) {
        return searchInNode(word, 0, root);
    }
};