#include <iostream>
#include <vector>

using namespace std;

// dp[i][j] = max of two k-length path to [i][k-i] & [j][k-j]
// Explanation: https://leetcode.com/problems/cherry-pickup/discuss/109906/Annotated-C++-DP-Solution

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        int steps = 2*(N-1);
        vector<vector<int>> dp(N, vector<int>(N,-1));
        dp[0][0] = grid[0][0];
        for (int k=1; k<=steps; ++k)
        {
            vector<vector<int>> cur(N, vector<int>(N,-1));
            // iterate first edge
            for (int i=max(0, k-N+1); i<N && i <=k ; ++i)
            {
                // iterate second edge
                for (int j=max(0, k-N+1); j<N && j<=k ; ++j)
                {
                    // skip blocked path
                    if (grid[i][k-i] <0 || grid[j][k-j] < 0)
                    {
                        continue;
                    }
                    // step from 4 cases
                    int cherry = dp[i][j];
                    if (i>0) cherry = max(cherry, dp[i-1][j]);
                    if (j>0) cherry = max(cherry, dp[i][j-1]);
                    if (i>0 && j>0) cherry = max(cherry, dp[i-1][j-1]);
                    if (cherry <0 )
                    {
                        continue;
                    }
                    cherry += grid[i][k-i] + (i==j?0:grid[j][k-j]);
                    cur[i][j] = cherry;
                }
            }
            helper(cur);
            cout << endl;
            swap(dp, cur);
        }
        return dp[N-1][N-1] > 0?dp[N-1][N-1]:0;
    }
    void helper(vector<vector<int>>& board)
    {
        for (const auto& row:board)
        {
            for (auto ele:row)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<vector<int>> board= {
        {0,1,-1},
        {1,0,-1},
        {1,1,1}
    };
    Solution sol;
    auto res = sol.cherryPickup(board);
    cout << res << endl;
}
