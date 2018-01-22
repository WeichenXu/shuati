#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i =0; i < nums.size(); ++i)
        {
            while (nums[i] != i+1 && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i=0; i<nums.size(); ++i)
        {
            if (nums[i] != i+1)
            {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution sol;
    auto res = sol.findDuplicates(nums);
    for (auto n:res)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
