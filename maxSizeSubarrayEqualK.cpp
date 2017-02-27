#include <iostream>
#include <vector>
#include <unordered_map>

// 1. build a dictionary mapping
//    <sum[0 to index], index list in ascending order>
// 2. find the max (j-i+1) by iterating

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        using map_t = unordered_map<int, int>;
        map_t m;

        // 1. build the dictionary
        m[0] = -1;
        for (int i=0; i<nums.size(); ++i){
            int curSum = 0;
            if (!i){
                curSum = nums[i];
            }
            else {
                curSum = nums[i-1] + nums[i];
            }
            nums[i] = curSum;
            if (m.find(curSum) == m.end()){
                m[curSum] = i;
                //cout << "Insert sum " << curSum << ", at index " << i << endl;
            }
        }
        // 2. find the max gap
        int res = 0;
        for (int i=nums.size()-1; i>=0; --i){
            int pair = nums[i]-k;
            if (m.find(pair) != m.end()){
                res = max(res, i - m[pair]);
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int k = 6;
    auto res = sol.maxSubArrayLen(nums, k);
    cout << "The longest target subarray is " << res << endl;
    return 0;
}
