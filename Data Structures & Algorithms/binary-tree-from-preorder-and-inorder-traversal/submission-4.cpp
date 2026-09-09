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
#include <unordered_map>
using namespace std;
class Solution {
    private:
    unordered_map<int , int> inorderMap;
    int preorderIndex =0;
    TreeNode* build(vector<int>& preorder, int left, int right) {
    if( left>right) return nullptr;
    int rootvalue = preorder[preorderIndex++];
    TreeNode*root = new TreeNode(rootvalue);
    int mid = inorderMap[rootvalue];
    root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);

        return root;
    }
    

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inorderMap.clear();
        preorderIndex = 0;

        // Populate hash map for O(1) index lookups in inorder array
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
        
    }
    };

