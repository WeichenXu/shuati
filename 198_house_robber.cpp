#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // start iterating from 3rd element
        int size = nums.size();
        int robLast = 0, notRobLast = 0;
        for (int i=0; i<size; ++i)
        {
            auto tmp = notRobLast;
            notRobLast = max(notRobLast, robLast);
            robLast = tmp + nums[i];
        }

        return max(robLast, notRobLast);
    }
};

int main()
{
    vector<int> nums = {2,1,1,2};
    Solution sol;
    auto res = sol.rob(nums);
    cout << res;
    return 0;
}
