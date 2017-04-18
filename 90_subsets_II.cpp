#include <iostream>
#include <vector>

// 1. store key->count
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res, last;
        sort(nums.begin(), nums.end());
        res.push_back({});
        for (int i=0; i<nums.size(); ++i){
            if (!i || nums[i-1] != nums[i]){
                last = res;
            }            
            for (int j=0; j<last.size(); ++j){
                last[j].push_back(nums[i]);
                res.push_back(last[j]);
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,2,2,4};
    Solution sol;
    auto&& res = sol.subsetsWithDup(nums);
    for (auto& r:res){
        for (auto n:r){
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
