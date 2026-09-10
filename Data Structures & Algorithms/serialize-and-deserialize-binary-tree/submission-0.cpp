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

#include <string>
#include <sstream>

using namespace std;

class Codec {
private:
    // Helper to serialize using Preorder DFS (Root, Left, Right)
    void serializeDFS(TreeNode* node, string& out) {
        if (!node) {
            out += "#,";
            return;
        }

        out += to_string(node->val) + ",";
        serializeDFS(node->left, out);
        serializeDFS(node->right, out);
    }

    // Helper to deserialize using stringstream and Preorder DFS
    TreeNode* deserializeDFS(stringstream& ss) {
        string valStr;
        if (!getline(ss, valStr, ',')) return nullptr;

        if (valStr == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(valStr));
        node->left = deserializeDFS(ss);
        node->right = deserializeDFS(ss);

        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out = "";
        serializeDFS(root, out);
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeDFS(ss);
    }
};
