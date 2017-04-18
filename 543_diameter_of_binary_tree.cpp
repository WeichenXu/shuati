/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        recursive_helper(root);
        return max_diameter;
    }
private:
    int recursive_helper(TreeNode* root){
        if (root == nullptr)    return 0;
        int l = recursive_helper(root->left);
        int r = recursive_helper(root->right);
        max_diameter = max(max_diameter, l+r+1);
        return max(l,r)+1;
    }
    int max_diameter{0};
};
