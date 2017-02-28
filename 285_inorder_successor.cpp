#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// in-order traverse the tree, return the next one
// 1. recursive
// 2. iterative

class Solution {
public:
    // 1. recursive
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr){
            return root;
        }
        if (p->val >= root->val){
            return inorderSuccessor(root->right, p);
        }
        auto* l = inorderSuccessor(root->left, p);
        return l == nullptr ? root : l;
    }
};
