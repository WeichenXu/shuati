class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while (not q.empty())
        {
            long sum = 0.0;
            int count = q.size();
            queue<TreeNode*> nx;
            while (not q.empty())
            {
                auto* cur = q.front();
                sum += cur->val;
                if (cur->left)  nx.push(cur->left);
                if (cur->right) nx.push(cur->right);
                q.pop();
            }
            res.push_back(double(sum)/double(count));
            swap(q, nx);
        }
        return res;
    }
};
