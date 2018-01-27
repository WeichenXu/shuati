#include <iostream>
#include <vector>

using namespace std;

// len[i] maximum length which ends with nums[i]
// sum[i] sum number of mam length seq ends with nums[i]
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size();
        int len[size], sum[size];
        memset(len, 0, sizeof(int)*size);
        memset(sum, 0, sizeof(int)*size);
        int max_len = 0, res = 0;
        for (int i=0; i<size; ++i)
        {
            len[i] = sum[i] = 1;
            for (int j=0; j<i;++j)
            {
                if (nums[i] > nums[j])
                {
                    // number increase
                    sum[i] += ((len[i] == len[j]+1)?sum[j]:0);
                    // len increase
                    if (len[i] <= len[j])
                    {
                        len[i] = len[j]+1;
                        sum[i] = sum[j];
                    }
                }
            }
            if (len[i] > max_len)
            {
                max_len = len[i];
                res = sum[i];
            }
            else if (len[i] == max_len)
            {
                res += sum[i];
            }
            cout << len[i] << ", " << sum[i] << endl;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1,3,5,4,7};
    Solution sol;
    auto res = sol.findNumberOfLIS(nums);
    cout << res << endl;
    return 0;
}
