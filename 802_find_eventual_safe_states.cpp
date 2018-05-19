#include <iostream>
#include <vector>

// DFS
// Find cycle if existed
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int vertice = graph.size();
        vector<int> res;
        m_visited.resize(vertice, -1);
        for (int i=0; i<vertice; ++i)
        {
            m_inVisit.resize(vertice, false);
            if (not dfs(i, graph)) res.push_back(i);
        }
        return res;
    }
    // return 1 if cycle
    // return 0 otherwise
    int dfs(int cur, const vector<vector<int>>& graph)
    {
        if (m_visited[cur] >= 0)    return m_visited[cur];
        if (m_inVisit[cur]) return 1;
        m_inVisit[cur] = true;
        const auto& nx = graph[cur];
        for (const auto n:nx )
        {
            if (dfs(n, graph))
            {
                m_visited[cur] = 1;
                return 1;
            }
        }
        m_visited[cur] = 0;
        return 0;
    }
private:
    vector<int> m_visited;
    vector<bool> m_inVisit;
};

int main()
{
    vector<vector<int>> graph=
    {
        {1,2},
        {2,3},
        {5},
        {0},
        {5},
        {},
        {}
    };
    Solution sol;
    auto res = sol.eventualSafeNodes(graph);
    for (auto n:res)
    {
        cout << n << ", ";
    }
    cout << endl;
    return 0;
}
