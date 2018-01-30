#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum%2)  return false;
        sum = sum/2;
        sort(nums.begin(), nums.end());
        int size = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            if (nums[i] <= sum)
            {
                ++size;
            }
        }
        cout << size << endl;
        vector<bool> prev(sum+1, false);
        prev[0] = true;
        vector<bool> cur(sum+1, false);
        for (int i=1; i<=size; ++i)
        {
            fill(cur.begin(), cur.end(), false);
            for (int j=0; j<=sum; ++j)
            {
                cur[j] = prev[j];
                if (j >= nums[i])
                {
                    cur[j] = cur[j] | prev[j-nums[i]];
                }
                if (j == sum && cur[j])
                {
                    return true;
                }
            }
            for (auto n:cur)
            {
                cout << n << " ";
            }
            cout << endl;
            swap(cur, prev);
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,4,5};
    //vector<int> nums = {1,2,5};
    cout << sol.canPartition(nums) << endl;
    return 0;
}
