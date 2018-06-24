#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// dp[n][k] = dp[n-1][k] + dp[n-1][k-1] + ... + dp[n-1][k-n+1]
// dp[n][k+1] = dp[n-1][k+1] + dp[n-1][k] ... dp[n-1][k-n+2]
// dp[n][k+1] = dp[n-1][k+1] + dp[n][k] - dp[n-1][k-n+1]
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<int> dp(k+1, 0);
        dp[0] = 1;
        int mod = pow(10,9)+7;
        for (int i=1; i<n; ++i)
        {
            vector<int> nx(k+1, 0);
            nx[0] = 1;
            for (int j=1; j<=k; ++j)
            {
                nx[j] = (dp[j] + nx[j-1] - (j-i>0?dp[j-i-1]:0))%mod;
            }
            swap(nx, dp);
        }
        return dp[k];
    }
};

int main()
{
    int n=1000, k=300;
    Solution sol;
    auto res = sol.kInversePairs(n, k);
    cout << res << endl;
    return 0;
}
