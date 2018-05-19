#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> dp;
        int maxSize = -1, maxIdx = -1;
        for (int i=0; i<nums.size(); ++i)
        {
            int num = nums[i];
            int curDiv = -1, curMax = 1;
            for (int j=i-1; j>=0; --j)
            {
                const auto& pre = dp[j];
                if (num % nums[j] == 0 and pre.first + 1 > curMax)
                {
                    curMax = pre.first + 1;
                    curDiv = j;
                }
            }
            dp.emplace_back(curMax,curDiv);
            if (curMax > maxSize)
            {
                maxSize = curMax;
                maxIdx = i;
            }
        }
        vector<int> res;
        while (maxIdx >= 0)
        {
            res.push_back(nums[maxIdx]);
            maxIdx = dp[maxIdx].second;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1,2,3,6,7};
    Solution sol;
    auto res = sol.largestDivisibleSubset(nums);
    for (auto n:res)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
