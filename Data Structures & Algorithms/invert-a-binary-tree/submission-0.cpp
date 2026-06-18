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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // We're going to tackle this recursively.
        // The way I'm thinking about this is that we keep
        // proceeding down the tree until we reach the end leaves,
        // at which point we can trace our way back the tree
        // and we 'flip' both the left and right tree nodes as we
        // continue traversing backwards.

        if (!root) {
            return nullptr;
        }

        invertTree(root->left);
        invertTree(root->right);
        
        TreeNode* temp;
        temp = root->right;
        root->right = root->left;
        root->left = temp;

        return root;
    }
};
