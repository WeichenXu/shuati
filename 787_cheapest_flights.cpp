#include <iostream>
#include <vector>

using namespace std;

// bellman-ford

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> cur(n, INT_MAX);
        cur[src] = 0;
        for (int i=0; i<=K; ++i)
        {
            auto nx = cur;
            for (const auto &flight : flights)
            {
                int ss=flight[0],dd=flight[1],pp=flight[2];
                if (cur[ss] < INT_MAX)
                {
                    nx[dd] = min(nx[dd], cur[ss] + pp);
                    cout << ss << ", " << dd << " relax to " << nx[dd] << endl;
                }
            }
            cur = nx; 
        }
        return cur[dst] == INT_MAX ? -1 : cur[dst];
    }
};

int main()
{
    vector<vector<int>> flights = {
        {0,1,100},
        {1,2,100},
        {0,2,500}
    };
    Solution sol;
    auto res = sol.findCheapestPrice(3, flights, 0, 2, 1);
    cout << res << endl;
}
