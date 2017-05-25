/*Definition for a binary tree node.
 * struct TreeNode {
 *  *     int val;
 *   *     TreeNode *left;
 *    *     TreeNode *right;
 *     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *      * };
 *       */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST_helper(root, nullptr, nullptr);
    }
private:
    bool isValidBST_helper(TreeNode* root, TreeNode* lo, TreeNode* hi){
        if (root == nullptr){
            return true;
        }
        if ( (lo != nullptr && lo->val >= root->val) ||
             (hi != nullptr && hi->val <= root->val) ){
            return false;
        }
        return isValidBST_helper(root->left, lo, root) && isValidBST_helper(root->right, root, hi);
    } 
};
