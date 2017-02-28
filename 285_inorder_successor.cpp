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
    // 1. iteration
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        auto* suc = nullptr;
        while (root != nullptr){
            if (p->val < root->val){
                suc = root;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return suc;
    }
};
