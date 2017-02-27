#include <iostream>
#include <vector>
#include <unordered_map>

// 1. build a dictionary mapping
//    <sum[0 to index], index list in ascending order>
// 2. find the max (j-i+1) by iterating

// optimize: we could use only single iteration
using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        using map_t = unordered_map<int, int>;
        map_t m;

        // calculate the current sum and try to find farthest match 
        int sum = 0, res = 0;
        for (int i=0; i<nums.size(); ++i){
            sum += nums[i];
            if (m.find(sum) == m.end()){
                m[sum] = i;
            }
            if (sum == k){
                res = i+1;
            }
            else if (m.find(sum - k) != m.end()){
                res = max(res, i-m[sum-k]);
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
