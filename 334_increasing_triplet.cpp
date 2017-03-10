#include <iostream>
#include <vector>

#include <cassert>
// o(n) time and o(1) space

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // always rember the 2nd smallest one
        if (nums.size() < 3){
            return false;
        }
        int min_1 = nums[0], min_2 = INT_MAX;
        for (int i=1; i<nums.size(); ++i){
            int num = nums[i];
            if (num > min_2){
                return true;
            }
            else if (num > min_1){
                min_2 = num;
            }
            else{
                min_1 = num;
            }
        }

        return false;
    }
};

int main(){
    vector<int> nums1 = {1,2,3}; // t
    vector<int> nums2 = {3,2,1}; // f
    vector<int> nums3 = {1,2,0,3}; // t
    vector<int> nums4 = {1,2,0,1}; // f

    Solution sol;
    assert(sol.increasingTriplet(nums1) == true);
    assert(sol.increasingTriplet(nums2) == false);
    assert(sol.increasingTriplet(nums3) == true);
    assert(sol.increasingTriplet(nums4) == false);

    return 0;
}
