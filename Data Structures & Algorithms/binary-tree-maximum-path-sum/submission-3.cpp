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
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
    private:
    int maxpathsumval = INT_MIN;
    int dfs(TreeNode*node){ 
        if(!node) return 0;
        int leftGain = max(0,dfs(node->left));
        int rightGain = max( 0,dfs(node->right));
        int currentpathsum = node->val+leftGain+rightGain;
        maxpathsumval = max(maxpathsumval,currentpathsum);
        return node->val + max(leftGain,rightGain);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxpathsumval = INT_MIN;
        dfs(root);
        return maxpathsumval;

    }
};
