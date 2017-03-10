#include <iostream>
#include <vector>

// sum the number of 1 in each bit
// for each bit
// sum(i*(n-i))

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bits(32,0);
        // add the bits-1 of the number
        for(auto num:nums){
            int i=0;
            while(num){
                if (num & 0x1){
                    ++ bits[i];
                }
                num = (num >> 1);
                ++i;
            }
        }

        // sum the different bits
        int s = nums.size();
        int res = 0;
        for (const auto b:bits){
            res += (b)*(s-b);
        }
        return res;
    }
};

int main(){
    vector<int> nums = {4, 14, 2};
    Solution sol;
    auto res = sol.totalHammingDistance(nums);
    cout << "Result is " << res << endl;
    return 0;
}
