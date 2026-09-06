/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #include <vector>

using namespace std;

class Solution {
private:
    void dfs(TreeNode* node, int level, vector<vector<int>>& result) {
        if (!node) return;

        // If visiting this level for the first time, add a new level list
        if (level == result.size()) {
            result.push_back(vector<int>());
        }

        // Place current node value into its corresponding level list
        result[level].push_back(node->val);

        // Recurse down to left and right subtrees
        dfs(node->left, level + 1, result);
        dfs(node->right, level + 1, result);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
};