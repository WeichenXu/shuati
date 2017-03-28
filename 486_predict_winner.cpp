#include <iostream>
#include <vector>

#include <cassert>

// 1. Each time when player select a number in range[s,e]
//    cache[i][j] = whether user1 get more points than opponent

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        cache.clear();
        cache.resize(size, vector<int>(size, INT_MIN));
        return helper(nums, 0, size-1) >= 0;
    }

private:
    int helper(vector<int>& nums, int l, int r){
        if (cache[l][r] == INT_MIN){
            cache[l][r] = ( l == r ? nums[l] : 
                max(nums[l]-helper(nums, l+1, r), nums[r]-helper(nums, l, r-1)) );
        }
        return cache[l][r];
    }
    vector<vector<int>> cache;
};

int main(){
    vector<int> nums1 = {1,5,2};
    vector<int> nums2 = {1,5,233,7};
    Solution sol;

    assert(sol.PredictTheWinner(nums1) == false);
    assert(sol.PredictTheWinner(nums2) == true);
    return 0;
}
