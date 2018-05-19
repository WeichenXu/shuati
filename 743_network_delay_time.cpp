#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> delay(N+1, INT_MAX);
        delay[K] = 0;
        for (int i=1; i<=N; ++i)
        {
            auto nx = delay;
            for (const auto&edge:times)
            {
                int src=edge[0], dst=edge[1], time=edge[2];
                if (delay[src] < INT_MAX)
                {
                    nx[dst] = min(nx[dst], delay[src]+time);
                }
            }
            swap(nx, delay);
        }
        int res = 0;
        for (int i=1; i<=N; ++i)
        {
            res  = max(res, delay[i]);
        }
        return res == INT_MAX ? -1:res;
    }
};

int main()
{
    vector<vector<int>> edges={
        {2,1,1}, {2,3,1}, {3,4,1}
    };
    Solution sol;
    auto res = sol.networkDelayTime(edges, 4, 2);
    cout << res << endl;
    return res;
}
