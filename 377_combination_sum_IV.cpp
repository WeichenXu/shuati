#include <iostream>
#include <vector>

// 1. sort the numbers
// 2. backtracking

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        helper(nums, target);
        return res;
    }

private:
    void helper(vector<int>& nums, int target){
        if(!target){
            ++res;
        }
        if (target < 0){
            return;
        }
        for (int i=0; i<nums.size(); ++i){
            helper(nums, target-nums[i]);
        }
    }
    int res;
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
