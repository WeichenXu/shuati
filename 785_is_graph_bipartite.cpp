#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* BFS
// coloring graph
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<bool> visited(nodes, false);
        vector<int> color(nodes, -1);
        queue<int> q;
        for (int i=0; i<nodes; ++i)
        {
            if (not visited[i])
            {
                color[i] = 0;
                visited[i] = true;
                q.push(i);
                while (not q.empty())
                {
                    int cur = q.front();
                    q.pop();
                    for (auto nx:graph[cur])
                    {
                        if (color[nx] == color[cur]) return false;
                        color[nx] = (color[cur]+1)%2;
                        if (not visited[nx]) q.push(nx);
                        visited[cur] = true;
                    }
                }
            }
        }
        return true;
    }
};
*/

// DFS
// coloring graph
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<bool> visited(nodes, false);
        vector<int> color(nodes, -1);
        queue<int> q;
        for (int i=0; i<nodes; ++i)
        {
            if (not visited[i])
            {
                color[i] = 0;
                visited[i] = true;
                q.push(i);
                while (not q.empty())
                {
                    int cur = q.front();
                    q.pop();
                    for (auto nx:graph[cur])
                    {
                        if (color[nx] == color[cur]) return false;
                        color[nx] = (color[cur]+1)%2;
                        if (not visited[nx]) q.push(nx);
                        visited[cur] = true;
                    }
                }
            }
        }
        return true;
    }
};
*/

int main()
{
    Solution sol;
    vector<vector<int>> graph = {
        {1,2,3},{0,2},{0,1,3},{0,2}
    };
    auto res = sol.isBipartite(graph);
    cout << res << endl;
    return 0;
}
