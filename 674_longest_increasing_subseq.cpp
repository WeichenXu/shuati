class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int pre = 1, res = nums.empty()?0:1;
        for (int i=1; i<nums.size(); ++i)
        {
            if(nums[i] > nums[i-1]) 
            {
                res = max(++pre, res);
            }
            else pre = 1;
        }
        return res;
    }
};
