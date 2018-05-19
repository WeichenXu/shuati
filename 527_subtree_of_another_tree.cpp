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
    string toString(TreeNode* s)
    {
        return s==nullptr?"N":"["+to_string(s->val)+",R=("+toString(s->left)+"),L=("+toString(s->right)+")]";
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return toString(s).find(toString(t)) != string::npos;
    }
};
