#include <iostream>
#include <vector>

// DP: dp[i,j] = min(x in i-j, x + max(dp(i, x-1), dp(x+1, j)))

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n, vector<int>(n,0));
        for (int l = 2; l <= n; ++l){
            for (int i=0; i < n-l+1; ++i){
                int j = i+l-1;
                dp[i][j] = INT_MAX;
                for (int k=i; k <= j; ++k){
                    dp[i][j] = min(dp[i][j],
                        k+1 + max( k-1>=i?dp[i][k-1]:0, k+1<=j?dp[k+1][j]:0 ));
                }
            } 
        }
        return dp[0][n-1];
    }
};

int main(){
    Solution sol;
    auto res = sol.getMoneyAmount(2);
    cout << res << endl;
    return 0;
}
