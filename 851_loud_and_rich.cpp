#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // 1. topological sort
        const int size = quiet.size();
        m_visited.resize(size, false);
        m_start.resize(size, true);
        m_graph.resize(size);
        for (const auto& ri:richer)
        {
            m_graph[ri[0]].insert(ri[1]);
            m_start[ri[1]] = false;
        }
        for (int i=0; i<size; ++i)
        {
            if (m_start[i]) dfs(i);
        }
        // 2. apply max value
        reverse(m_topolo.begin(), m_topolo.end());
        vector<int> res(size, -1);
        for (auto cur:m_topolo)
        {
            if (res[cur] == -1) res[cur] = cur;
            for (auto nx:m_graph[cur])
            {
                if (quiet[nx] >= quiet[cur])    
                {
                    quiet[nx] = quiet[cur];
                    res[nx] = res[cur];
                }
            }
        }
        return res;
    }
    void dfs(int cur)
    {
        if (m_visited[cur]) return;
        m_visited[cur] = true;
        for (auto nx:m_graph[cur])
        {
            dfs(nx);
        }
        m_topolo.push_back(cur);
    }
    vector<bool> m_visited, m_start;
    vector<int> m_topolo;
    vector<unordered_set<int>> m_graph;
};

int main()
{
    vector<vector<int>> richer = {
        {1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}
    };
    vector<int> quiet = {3,2,5,4,6,1,7,0};
    Solution sol;
    auto res = sol.loudAndRich(richer, quiet);
    for (auto r:res)    cout << r <<" ";
    cout << endl;
    return 0;
}
