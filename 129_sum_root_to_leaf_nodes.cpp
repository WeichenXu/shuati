class Solution {
public:
    int sumNumbers(TreeNode* root) {
        // BFS
        int res = 0;
        if (root == nullptr)    return res;
        queue<pair<int, TreeNode*>> cur;
        cur.push({0, root});
        while (not cur.empty())
        {
            auto p = cur.front();
            cur.pop();
            int val = p.first*10 + p.second->val;
            bool isLeaf = true;
            if (p.second->left != nullptr)
            {
                cur.push({val, p.second->left});
                isLeaf = false;
            }
            if (p.second->right != nullptr)
            {
                cur.push({val, p.second->right});
                isLeaf = false;
            }
            res += isLeaf?val:0;
        }
        return res;
    }
};
