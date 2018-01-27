#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // find whether we could make sum/2 combination
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
        {
            return false;
        }
        size_t size = nums.size();

        // sort nums for early return
        // sort(nums.begin(), nums.end());
        bool dp[size+1][sum/2+1];
        memset(dp, false, sizeof(bool)*(size+1)*(sum/2+1));
        int too_large=size;
        for (int i=1; i<=too_large; ++i)
        {
            for (int j=0;j<=sum/2; ++j)
            {
                if (!j)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] |= dp[i-1][j];
                    if (j>=nums[i]){
                        dp[i][j] |= dp[i-1][j-nums[i]];
                    }
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[size][sum/2];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,5};
    cout << sol.canPartition(nums) << endl;
    return 0;
}
