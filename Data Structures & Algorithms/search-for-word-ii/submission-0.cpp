#include <vector>
#include <string>

struct TrieNode {
    TrieNode* children[26];
    std::string word; // Holds the full word if this node ends one

    TrieNode() {
        word = "";
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
        curr->word = word; // Store word at leaf node
    }

    void dfs(std::vector<std::vector<char>>& board, int r, int c, TrieNode* curr, std::vector<std::string>& result) {
        char ch = board[r][c];
        int index = ch - 'a';

        // Base cases: invalid character or no matching branch in Trie
        if (ch == '#' || !curr->children[index]) {
            return;
        }

        curr = curr->children[index];

        // Found a word!
        if (!curr->word.empty()) {
            result.push_back(curr->word);
            curr->word = ""; // Clear to avoid adding duplicates
        }

        // Mark cell as visited
        board[r][c] = '#';

        // Explore 4 directionally adjacent cells
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()) {
                dfs(board, nr, nc, curr, result);
            }
        }

        // Backtrack: restore original character
        board[r][c] = ch;
    }

public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        root = new TrieNode();

        // 1. Build Trie with all target words
        for (const std::string& w : words) {
            insert(w);
        }

        std::vector<std::string> result;
        int rows = board.size();
        int cols = board[0].size();

        // 2. Start DFS from every cell on the board
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root, result);
            }
        }

        return result;
    }
};