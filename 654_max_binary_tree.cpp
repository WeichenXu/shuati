class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    TreeNode* helper(const vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        // find largest value
        int mmax = nums[left], index=left;
        for (int i=left+1; i<=right; ++i)
        {
            if (mmax < nums[i])
            {
                mmax = nums[i];
                index = i;
            }
        }
        TreeNode* cur = new TreeNode(mmax);
        cur->left = helper(nums, left, index-1);
        cur->right = helper(nums, index+1, right);
        return cur;
    }
};
