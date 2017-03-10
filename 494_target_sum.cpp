#include <iostream>

#include <vector>
#include <unordered_map>

// 1. must add '+' or '-' before the num
// 2. return the possible combination 

// DP: maintain current combination to i
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = nums.size(), res = 0;
        unordered_map<int, int> m, nx;
        m[nums[0]] += 1;
        m[-nums[0]] += 1; 
        // iterate all possible combination, bit 0 = +, 1 = -
        for (int i=1; i < size; ++i){
            nx.clear();
            for (auto it = m.begin(); it != m.end(); ++it){
                nx[it->first + nums[i]] += m[it->first];
                nx[it->first - nums[i]] += m[it->first];
            }
            swap(m, nx);
        }
        
        return m[S];
    }
};

int main(){
    vector<int> nums = {1, 1 ,1, 1, 1};
    int S = 3;
    Solution sol;
    auto res = sol.findTargetSumWays(nums, S);
    cout << "Res is :" << res << endl;
    return 0;
}
