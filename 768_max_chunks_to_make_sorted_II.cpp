#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int size = arr.size();
        vector<int> revMin(size, 0);
        int m = INT_MAX;
        for (int i=size-1; i >= 0; --i)
        {
            m = min(m, arr[i]);
            revMin[i] = m;
        }
        int curMax=-1, res = 0;
        for (int i=0; i<size; ++i)
        {
            if (revMin[i] >= curMax) ++res;
            curMax = max(curMax, arr[i]);
        }
        return res;
    }
};

int main()
{
    //vector<int> nums = {2,1,3,4,4};
    vector<int> nums = {1,0,1,3,2};
    //vector<int> nums = {5,1,1,8,1,6,5,9,7,8};
    Solution sol;
    auto res = sol.maxChunksToSorted(nums);
    cout << res << endl;
    return 0;
}
