//https://leetcode.com/problems/unique-letter-string/discuss/128952/One-pass-O(N)-Straight-Forward
class Solution {
public:
    int uniqueLetterString(string S) {
        const int N = S.length(), mod = pow(10,9)+7;
        int dp[26][2], res = 0;
        memset(dp, -1, sizeof(int)*52);
        for (int i=0; i<N; ++i)
        {
            int c = S[i]-'A';
            res = (res + ((dp[c][1]-dp[c][0])*(i-dp[c][1]))%mod)%mod;
            dp[c][0] = dp[c][1];
            dp[c][1] = i;
        }
        for (int i=0; i<26; ++i)
        {
            res  = (res+((N-dp[c][1])*(dp[c][1] - dp[c][0]))%mod)%mod;
        }
        return res;
    }
};
