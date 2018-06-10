#include <iostream>

using namespace std;

class Solution {
public:
    int numTilings(int N) {
        //https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116581/Detail-and-explanation-of-O(n)-solution-why-dpn2*dn-1+dpn-3
        //dp[n] = 2dp[n-1] + dp[n-3]
        if (not N)  return 1;
        int mod = pow(10, 9) + 7;
        vector<int> dp(N,0);
        dp[0] = 1, dp[1] = 2, dp[2] = 5;
        for (int i=3; i<N; ++i) dp[i] = ((2*dp[i-1])%mod + dp[i-3])%mod;
        return dp[N-1];
    }
};

