#include<iostream>
#include <vector>

// use the iterative way

using namespace std;

class Solution{
public:
    
    int search(vector<int>& nums, int target){
        int lo=0, hi=nums.size()-1;
        while(lo < hi){
            int mid = ((lo+hi) >> 1);
            if (nums[mid] == target){
                return mid;
            }
            if (nums[lo] <= nums[mid]){
                if (target >= nums[lo] && target <= nums[mid]){
                    hi = mid;
                }
                else{
                    lo = mid+1;
                }
            }
            else{
                if (target >= nums[lo] || target <= nums[mid]){
                    hi = mid;
                }
                else{
                    lo = mid+1;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {3,4,0,1,2};
    Solution sol;
    int target = 1;
    cout << "Find the target: " << target << ", at index: " << sol.search(nums, target) << endl;
    return 0;
}
