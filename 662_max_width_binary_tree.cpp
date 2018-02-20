class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        using pair_t = pair<int, TreeNode*>;
        queue<pair_t> q({{1, root}})
        int res = 1;
        while (not q.empty())
        {
            queue<pair_t> nx;
            while (not q.empty())
            {
                const auto& p = q.front();
                auto curIdx = p.first;
                const auto* cur = p.second;
                if (cur->left != nullptr)
                {
                    nx.push({curIdx*2-1, cur->left});
                }
                if (cur->right != nullptr)
                {
                    nx.push({curIdx*2, cur->right});
                }
                q.pop();
            }
            if (not nx.empty())
            {
                res = max(res, nx.back().first-nx.front().first+1);
            }
            swap(nx, idx);
        }
        return res;
    }
};
