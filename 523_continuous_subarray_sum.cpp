#include <iostream>
#include <vector>
#include <unordered_map>
// 1. keep an unordered_set<remain>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> s;
        int cur = 0;
        s[0] = -1;
        for (int i=0; i<nums.size(); ++i){
            cur = k ? (cur+nums[i])%k : cur+nums[i];
            auto it = s.find(cur);
            if (it != s.end() ){
                if (it->second != i-1)
                    return true;
            }
            else    s[cur] = i;
        }
        return false;
    }
};

int main(){
    vector<int> nums = {1, 1};
    int k = 2;
    Solution sol;
    auto res = sol.checkSubarraySum(nums, k);
    cout << "Res is: " << res << endl;
}
