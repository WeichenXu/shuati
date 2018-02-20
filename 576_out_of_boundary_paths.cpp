#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<long>> dp(m, vector<long>(n, 0));
        if (N <= 0) return 0;
        dp[i][j] = 1;
        vector<pair<int,int>> directions= {{0,1},{0,-1},{1,0},{-1,0}};
        long sum = 0;
        // iterate N steps;
        // 1. sum the out path
        // 2. update dp status
        for (int k=0; k<N; ++k)
        {
            vector<vector<long>> nx(m, vector<long>(n, 0));
            for (int ii = 0; ii<m; ++ii)
            {
                for (int jj=0; jj<n; ++jj)
                {
                    for (auto&dir : directions)
                    {
                        int nx_i = dir.first + ii, nx_j = dir.second + jj; 
                        if (nx_i >=0 && nx_i < m && nx_j >=0 && nx_j < n)
                        {
                            nx[nx_i][nx_j] += dp[ii][jj];
                            nx[nx_i][nx_j] %= ((long)pow(10,9) + 7);
                        }
                        else
                        {
                            sum += dp[ii][jj];
                            sum %= ((long)pow(10,9) + 7);
                        }
                    }
                }
            }
            swap(dp, nx);
        }
        return (int)sum;
    }
};

int main()
{
    Solution sol;
    cout << sol.findPaths(36,5,50,15,3) << endl;
}
