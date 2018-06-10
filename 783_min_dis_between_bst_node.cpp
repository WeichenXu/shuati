class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        if (root == nullptr)    return;
        minDiffInBST(root->left);
        m_res = min(m_res, root->val - m_lastVal);
        m_lastVal = root->val;
        minDiffInBST(root->right);
        return m_res;
    }
    long m_lastVal{INT_MIN}, m_res{INT_MAX};
};
