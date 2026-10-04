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

class PrefixTree {
private:
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(std::string word) {
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
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->children[index]) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isWord;
    }
    
    bool startsWith(std::string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!curr->children[index]) {
                return false;
            }
            curr = curr->children[index];
        }
        return true;
    }
};