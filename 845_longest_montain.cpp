#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int res = 0;
        if (A.size() < 3)  return res;
        int len[2] = {1,0};
        for (int i=1; i<A.size(); ++i)
        {
            if (A[i] == A[i-1])
            {
                len[0] = 1, len[1] = 0;
            }
            else if(A[i] > A[i-1])
            {
                if (len[1])
                {
                    len[0] = 1, len[1] = 0;
                }
                ++len[0];
            }
            else
            {
                ++len[1];
                if (len[0] > 1) res = max(res, len[0]+len[1]);
            }
            cout << "A[i]" << A[i] << "-> " << len[0] << ", " << len[1] << endl;
        }
        return res >= 3 ? res:0;
    }
};

int main()
{
    vector<int> nums = {0,1,2,2,3,4};
    //vector<int> nums = {2,1,4,7,3,2,5};
    Solution sol;
    auto res = sol.longestMountain(nums);
    cout << res << endl;
}
