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
        helper(root);
        while (root != nullptr)
        {
            root -> left = nullptr;
            root = root->right;
        }
    }
    pair<TreeNode*, TreeNode*> helper(TreeNode* cur)
    {
        if (cur == nullptr)
        {
            return {nullptr, nullptr};
        }
        auto* last = cur;
        const auto& pLeft = helper(cur->left);
        auto* right = cur->right;
        if (pLeft.first != nullptr)
        {
            cur->right = pLeft.first;
            last = pLeft.second;
        }
        const auto& pRight = helper(right);
        if (pRight.second != nullptr)
        {
            last->right = pRight.first;
            last = pRight.second;
        }
        return {cur, last};
    }
};
