#include <iostream>
#include <vector>

// 1. sort the numbers
// 2. backtracking

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1);
        fill(dp.begin(), dp.end(), -1);
        dp[0] = 1;
        helper(nums, target);
        return dp[target];
    }

private:
    int helper(vector<int>& nums, int target){
        if(dp[target] == -1){
            int sum = 0;
            for (int i=0; i<nums.size(); ++i){
                if (target >= nums[i]){
                    sum += helper(nums, target-nums[i]);
                }
            }
            dp[target] = sum;
        }
        return dp[target];
    }
    vector<int> dp;
};

int main(){
    vector<int> nums = {
        1, 2, 3
    };
    Solution sol;
    auto res = sol.combinationSum4(nums, 32);
    cout << "Combination sum: " << res << endl;
    return 0;
}
