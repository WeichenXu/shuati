#include <iostream>
#include <vector>

using namespace std;

// score the add/remove edge of each k step rotation
class Solution {
public:
    int bestRotation(vector<int>& A) {
        int len = A.size();
        vector<int> v(len, 0);
        for (int i=0; i<len; ++i)
        {
            int num = A[i];
            if (num == 0 || num == len) continue;
            if (num <= i)
            {
                v[0] += 1;
                v[i-num+1] -= 1;
                if (i+1 < len)  v[i+1] += 1;
            }
            else
            {
                v[i+1] += 1;
                int removeSteps = len + i - num + 1;
                if (removeSteps < len) v[removeSteps] -= 1;
            }
        }
        int res = -1, maxScore = -1, tmpScore = 0;
        for (int i=0; i<len; ++i)
        {
            tmpScore += v[i];
            if (tmpScore > maxScore)
            {
                res = i;
                maxScore = tmpScore;
            }
        }
        return res;
    }
};

int main()
{
    //vector<int> nums = {2,3,1,4,0};
    //vector<int> nums = {1,3,0,2,4};
    vector<int> nums = {0,1,1,6,9,3,8,7,9,8};
    Solution sol;
    auto res = sol.bestRotation(nums);
    cout << res << endl;
    return 0;
}
