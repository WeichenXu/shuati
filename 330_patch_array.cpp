#include <iostream>
#include <vector>

#include <cassert>
// ##### add minimum patch of numbers so we could generate all combination form [1,n]
// current range: [0, m)
// if we add a number <= m, nx range would be: [0, m+num]

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, add = 0, i = 0;
        int size = nums.size();
        cout << "Starting find mini path for n:" << n << endl;
        while(miss <= n){
            if (i < size && nums[i] <= miss){
                miss += nums[i++];
            }
            else{
                ++add;
                miss = (miss << 1);
            }
        }
        cout << "Min Patch is: " << add << endl;

        return add;
    }
};

int main(){
    vector<pair<vector<int>, int>> nums={
        {{1}, 2},
        {{1,2}, 5},
        {{1,5,10}, 20}
    };
    vector<int> res = {
        1,
        1,
        2
    };
    Solution sol;
    for (int i=0; i < nums.size(); ++i){
        assert(sol.minPatches(nums[i].first, nums[i].second) == res[i]);
    }
}
