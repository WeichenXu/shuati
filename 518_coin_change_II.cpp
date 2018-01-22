#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(size+1, 0));
        for (int i = 1; i<=amount; ++i)
        {
            for (int j=1; j<=size; ++j)
            {
                int num = dp[i][j-1];
                int times = i/coins[j-1];
                for (int k=1; k<=times; ++k)
                {
                    if (k*coins[j-1] == i)
                    {
                        ++num;
                        continue;
                    }
                    num += dp[i-k*coins[j-1]][j-1];
                }
                dp[i][j] = num;
                cout << dp[i][j] << " ";
            }
            cout <<endl;
        }
        return dp[amount][size];
    }
};

int main()
{
    Solution sol;
    vector<int> coins{1,2,5};
    int sum = 5;
    cout << sol.change(sum, coins) << endl;
    return 0;
}
