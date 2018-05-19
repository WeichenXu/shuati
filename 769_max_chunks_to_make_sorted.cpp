#include <iostream>
#include <vector>

using namespace std;

// for arr is permutation
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, curMax = -1;
        for (int i = 0 ; i<arr.size(); ++i)
        {
            curMax = max(curMax, arr[i]);
            if (curMax == i)    ++res;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1,2,0,3};
    Solution sol;
    auto res = sol.maxChunksToSorted(nums);
    cout << res << endl;
    return 0;
}
