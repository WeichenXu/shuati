#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int len = target.length();
        int n = 1 << len;
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        // use <int> mask to represent bit map for bits existence of target
        // 1111 are from small ones
        for (int i=0; i<n; ++i)
        {
            if (dp[i] != INT_MAX)
            {
                for (const auto& sticker:stickers)
                {
                    auto cur = i;
                    // match as many NEW chars as possible
                    for (auto ch:sticker)
                    {
                        for (int j = 0; j<len; ++j)
                        {
                            if (ch == target[j] && (cur&(0x1<<j)) == 0)
                            {
                                cur = cur|(0x1<<j);
                                dp[cur] = min(dp[cur], dp[i]+1);
                            }
                        }
                    }
                }
            }
        }
        return dp[n-1] == INT_MAX ? -1:dp[n-1];
    }
};

int main()
{
    string target = "theth";
    vector<string> stickers = {
        "where", "tch", "thh"
    };
    Solution sol;
    auto res = sol.minStickers(stickers, target);
    cout << res << endl;
}
