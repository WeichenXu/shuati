#include <iostream>
#include <vector>

// DP: keep dp[i] : the minimum number of subsequence in length of 'i' could end with

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size(), maxLen = 1;
        int dp[length+1];
        dp[0] = INT_MIN;
        for (auto i:nums){
            int idx = binarySearch(dp, maxLen, i);
            dp[idx] = i;
            if (idx >= maxLen)  ++maxLen;
        }
        return maxLen-1;
    }
private:
    // find the lower_bound of target in the array
    int binarySearch(int* dp, int len, int target){
        int lo = 0, hi = len-1;
        while (lo < hi){
            int mid = (lo + hi) >> 1;
            if (dp[mid] >= target){
                hi = mid;
            }
            else lo = mid+1;
        }
        return dp[lo]>=target ? lo:(lo+1);
    }
};

int main(){
    //vector<int> nums = {1, 1, 2, 1, 6};
    vector<int> nums = {};
    Solution sol;
    auto res = sol.lengthOfLIS(nums);
    cout << "Result is : " << res << endl;
    return 0;
}
