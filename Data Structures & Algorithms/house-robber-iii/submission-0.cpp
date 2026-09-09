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
#include <utility>
using namespace std;
class Solution {
    private:
    pair<int,int>dfs(TreeNode*node){
        if(!node) return {0,0};
        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);
        int rob = node->val + left.second + right.second;
        int skip = max(left.first, left.second) + max(right.first, right.second);
    return {rob, skip};
    }
        public:
    int rob(TreeNode* root) {
        pair<int, int> result = dfs(root);
        return max(result.first, result.second);
    }
};