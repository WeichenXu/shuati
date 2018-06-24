class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> res = {nullptr, nullptr};
        if (root == nullptr)    return res;
        if (root->val <= V)
        {
            auto r = splitBST(root->right, V);
            root->right = r[0];
            return {root, r[1]};
        }
        else
        {
            auto l = splitBST(root->left, V);
            root->left = r[1];
            return {r[0], root};
        }
        return res; 
    }
};
