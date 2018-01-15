#include <iostream>
#include <vector>

using namespace std;
// 1st and last are also exclusive
class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0;
        if (nums.size() == 1)
        {
            return nums[0];
        }
        for (int i=0; i < static_cast<int>(nums.size())-1; ++i)
        {
            if (i%2 == 0)
            {
                a = max(b, a+nums[i]);
            }
            else
            {
                b = max(a, b+nums[i]);
            }
        }
        int result = max(a,b);
        a = 0, b = 0;
        for (int i=1; i<nums.size(); ++i)
        {
            if (i%2 == 0)
            {
                a = max(b, a+nums[i]);
            }
            else
            {
                b = max(a, b+nums[i]);
            }
        }
        int result2 = max(a,b);
        return max(result, result2);
    }
};

int main()
{
    //vector<int> nums = {1,2,1,1};
    vector<int> nums = {1};
    Solution sol;
    auto res = sol.rob(nums);
    cout << res << "\n";
    return 0;
}
