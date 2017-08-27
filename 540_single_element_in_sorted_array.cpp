#include <iostream>
#include <vector>

#include <cassert>

// Binary Search
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = ( (l+r) >> 1 );
            // move mid to an even index 
            if ((mid-l+1) % 2)  --mid;
            if (nums[mid] == nums[mid-1])   l = mid+1;
            else r = mid-1;
        }
        return nums[l];
    }
};

int main(){
    Solution sol;
    vector<vector<int>>nums = {
        {1},
        {0,0,1},
        {0,1,1},
        {0,0,1,2,2}
    };
    vector<int> res = {1,1,0, 1};
    for (int i=0; i<nums.size() ;++i){
        assert(sol.singleNonDuplicate(nums[i]) == res[i]); 
    }
    return 0;
}
