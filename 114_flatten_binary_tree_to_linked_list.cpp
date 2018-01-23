#include <iostream>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        // use post-order
        if (root == nullptr)
        {
            return;
        }
        flatten(root->left);
        flatten(root->right);
        auto* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right != nullptr)
        {
            root = root->right;
        }
        root->right = tmp;
    }
};
