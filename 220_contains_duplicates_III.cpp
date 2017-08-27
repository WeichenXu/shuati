#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// Build binary-search tree with nums
// Query with upper/lower bound
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t<0 || k==0)    return false;
        multimap<long, long> mm;
        for (int i=0; i<nums.size(); ++i){
            mm.insert({nums[i], i});
        }
        for (const auto& it:mm){
            auto itlow = mm.lower_bound(it.first-t);
            auto ithigh = mm.upper_bound(it.first+t);
            using iter_t = map<int, int>::value_type;
            auto found = find_if(itlow, ithigh, [=](iter_t ii){ 
                    return abs(ii.second -it.second) <= k && (ii.second != it.second);
                });
            if (found != ithigh)  return true;
        }
        return false;
    }
};

int main(){
    vector<int> nums = {-1,INT_MAX};
    int k = 1;
    int t = INT_MAX;
    Solution sol;
    auto res = sol.containsNearbyAlmostDuplicate(nums, k, t);
    cout << res << endl;
}
