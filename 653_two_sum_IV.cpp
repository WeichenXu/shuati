class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr)    return false;
        if (m_targets.find(k-root->val) != m_targets.end()) return true;
        m_targes.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
private:
    unordered_set<int> m_targes;
};
