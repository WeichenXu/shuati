class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int v = 0;
        inOrder(root, v);
        return root;
    }
    void inOrder(TreeNode* n, int& v)
    {
        if (n == nullptr)   return;
        inOrder(n->right, v);
        v += n->val;
        n->val = v;
        inOrder(n->left, v);
    }
};
