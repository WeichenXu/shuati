#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        return dfs(r,c, N, K, K);
    }
    double dfs(int r, int c, int N, int K, int k)
    {
        if (r<0 || r>= N || c<0 || c>=N)  return 0.0;
        else if (k == 0) return 1.0;
        int key = k*N*N + r*N + c;
        auto it = m_cache.find(key);
        if (it != m_cache.end())    return it->second;
        vector<pair<int,int>> directions = {
            {-2,-1},{-1,-2},{-1,2},{1,-2},{2,-1},{-2,1}, {1,2},{2,1}
        };
        double res = 0.0;
        for (const auto& dir:directions)
        {
            res += 0.125 * dfs(r+dir.first, c+dir.second, N, K, k-1);
        }
        m_cache[key] = res;
        return res;
    }
private:
    unordered_map<int, double> m_cache;
};

int main()
{
    Solution sol;
    auto res = sol.knightProbability(8,5,6,4);
    cout << res << endl;
}
