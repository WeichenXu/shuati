#include <iostream>
#include <vector>

// 1. binary search, to crack down the correct value

using namespace std;

class Solution{
public:
    int splitArray(vector<int>& nums, int m){
        int lo = 0, hi = 0;
        for (int num:nums){
            lo = max(lo, num);
            hi += num;
        }
        // binary search
        while (lo < hi){
            int mid = ((lo + hi) >> 1);
            //bool passed = valid(nums, mid, m);
            //cout << "For target = " << mid << ", condition is " << passed << endl;
            if ( valid(nums, mid, m) ){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }

        return lo;
    }
private:
    // Given the nums array and target max subarray, return whether m could be valid
    bool valid(const vector<int>& nums, const int target, const int m) const{
        int sum = 0, i = 0, slots = 1;
        while (i < nums.size()){
            sum += nums[i];
            if (sum > target){
                sum = nums[i];
                ++ slots;
            }
            ++i;
        }
        return slots <= m;
    }
};

int main(){
    vector<int> nums = {7, 2, 5, 10, 8};
    Solution sol;
    int m=2;
    auto res = sol.splitArray(nums, m);
    cout << "Minimized sum of the array is " << res << endl;
    return 0;
}
