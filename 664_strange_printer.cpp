#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int len  = s.length();
        if (not len) return 0;
        string target = string(1, s[0]);
        for (int i=1; i<len; ++i)
        {
            if (s[i] == target.back())  continue;
            target.append(1, s[i]);
        }
        len = target.length();
        cout << "target: " << target << ", len=" << len << endl;
        vector<vector<int>> dp(len, vector<int>(len, 1));
        for (int l=2; l<=len; ++l)
        {
            for (int i=0; i<=len-l; ++i)
            {
                int left = i, right = i+l-1;
                dp[left][right] = (target[left] == target[right] ? 0:1) + min(dp[left][right-1], dp[left+1][right]);
                char key = target[right];
                for (int j=left+1; j<right; ++j)
                {
                    if (key == target[j])
                    {
                        dp[left][right] = min(dp[left][right], dp[left][j-1] + dp[j][right]);
                    }
                }
            }
        }
        return dp[0][len-1];
    }
};

int main()
{
    string s = "ccdcadbddbaddcbccdcdabcbcddbccdcbad";
    //string s = "abaabc";
    Solution sol;
    cout << sol.strangePrinter(s) << endl;
    return 0;
}
