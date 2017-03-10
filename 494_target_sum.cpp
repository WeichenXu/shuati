#include <iostream>
#include <numeric>

#include <vector>
#include <unordered_map>

// 1. must add '+' or '-' before the num
// 2. return the possible combination 

// DP: maintain current combination to i
// sum(positive) - sum(negative) = target + sum(nums), sum(positive) = sum - sum(negative)
// 2*sum(positive) = target + sum

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
       int sum = accumulate(nums.begin(), nums.end(), 0);
       return ((sum+S)&0x1 || S>sum) ? 0 : targetSet(nums, (sum+S)>>1 ); 
    }
private:
    int targetSet(vector<int>& nums, int t){
        int dp[t+1];
        dp[0] = 1;
        for (auto num:nums){
            for (int i=t; i>=num; --i){
                dp[i] += dp[i-num];
            }
        }
        return dp[t];
    }
};

int main(){
    vector<int> nums = {1,1,1,1,1};
    int S = 3;
    Solution sol;
    auto res = sol.findTargetSumWays(nums, S);
    cout << "Res is :" << res << endl;
    return 0;
}
