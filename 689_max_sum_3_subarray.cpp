#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    struct node{
        int m_sum{0};
        vector<int> m_endIdx;
    };
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        nums.insert(nums.begin(), 0);
        const int size = nums.size();
        vector<vector<node>> dp(4, vector<node>(size, {0, {}}));
        int sum = accumulate(nums.begin(), nums.begin()+k, 0);
        for (int i=k; i<size; ++i)
        {
            sum += (nums[i]-nums[i-k]);
            for (int j=3; j>0; --j)
            {
                if (dp[j][i].m_sum < dp[j][i-1].m_sum)
                {
                    dp[j][i].m_sum = dp[j][i-1].m_sum;
                    dp[j][i].m_endIdx = dp[j][i-1].m_endIdx;
                }
                if (dp[j][i].m_sum < dp[j-1][i-k].m_sum + sum)
                {
                    dp[j][i].m_sum = dp[j-1][i-k].m_sum + sum;
                    dp[j][i].m_endIdx = dp[j-1][i-k].m_endIdx;
                    dp[j][i].m_endIdx.push_back(i);
                }
            }
        }
        auto res = dp[3][size-1].m_endIdx;
        for_each(res.begin(), res.end(), [&](int& n){n=n-k;});
        return res;
    }
};

int main()
{
    vector<int> nums = {1,2,3,0,4,5,0,6,7};
    int k = 2;
    Solution sol;
    auto res = sol.maxSumOfThreeSubarrays(nums, k);
    for_each(res.begin(), res.end(), [](const int n){cout << n << " ";});
    cout << endl;
    return 0;
}
