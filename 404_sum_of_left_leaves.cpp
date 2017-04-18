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
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeft_recursive(root, false);        
    }
private:
    int sumOfLeft_recursive(TreeNode* root, bool isLeft){
        int res = 0;
        if (root != nullptr) {
            if (root->left == nullptr && root->right == nullptr && isLeft){
                res += root->val;
            }    
            res += sumOfLeft_recursive(root->left, true);
            res += sumOfLeft_recursive(root->right, false);
        }
        return res;
    }
};
