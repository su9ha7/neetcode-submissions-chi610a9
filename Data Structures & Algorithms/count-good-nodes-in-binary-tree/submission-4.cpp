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
#include <algorithm>

using namespace std;

class Solution {
private:
    int dfs(TreeNode* node, int maxsofar) {
        if (!node) return 0;

        int count = 0;
        if (node->val >= maxsofar) {
            count = 1;
            maxsofar = node->val;
        }

        count += dfs(node->left, maxsofar);
        count += dfs(node->right, maxsofar);

        return count;
    }

public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, root->val);
    }
};