#include <iostream>
#include <vector>
#include <stack>

#include <algorithm>

#include <cassert>

// Find the max length array (binary), with same 0s and 1s
// Keep a current stack of number for match
// update nums[i] to max subarray end at i

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        stack<int> zeros, ones;
        int res = 0;
        for (int i=0; i<nums.size(); ++i){
            int cur = nums[i];
            // stack ForMatch is empty 
            if ((cur && zeros.empty()) || (!cur && ones.empty())){
                nums[i] = 0;
            }
            else{
                int last;
                if (cur){
                    last = zeros.top();
                    zeros.pop();
                }
                else{
                    last = ones.top();
                    ones.pop();
                }
                nums[i] =  (i - last + 1 + nums[last-1]);
            }
            // push into ForMatch stack
            if (cur)    ones.push(i);
            else zeros.push(i);
            res = max(res, nums[i]);
        }
        return res;
    }
};

int main(){
    Solution sol;
    
    vector<int> nums1 = {0,0,0};
    vector<int> nums2 = {0,0,1};
    vector<int> nums3 = {1,0,0};
    vector<int> nums4 = {1,0,1,0};
    vector<int> nums5 = {0,0,1,0,0,0,1,1};

    assert(sol.findMaxLength(nums1) == 0);
    assert(sol.findMaxLength(nums2) == 2);
    assert(sol.findMaxLength(nums3) == 2);
    assert(sol.findMaxLength(nums4) == 4);
    assert(sol.findMaxLength(nums5) == 6);

    return 0;
}
