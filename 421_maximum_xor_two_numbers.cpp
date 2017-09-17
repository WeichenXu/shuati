#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        for (int i=31; i>=0; --i)
        {
            mask = mask | (1<<i);
            // list candidates
            unordered_set<int> cands;
            for (auto num:nums){
                cands.insert(num&mask);
            }
            int tmp = max | (1<<i);
            for (auto num:cands){
                if (cands.find(num^tmp) != cands.end()){
                    max = tmp;
                    break;
                }
            }
        }
        return max;
    }
};

int main(){
    vector<int> nums = {3,5,10,25,8};
    Solution sol;
    auto res = sol.findMaximumXOR(nums);
    cout << res << endl;
    return 0;
}
