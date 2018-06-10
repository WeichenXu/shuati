#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// BFS
// Use a int to represent unique state to avoid infinite seach
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int size = graph.size();
        unordered_set<int> visited;
        queue<int> q;
        for (int i=0; i<size; ++i)
        {
            int state = (i<<20)|(1<<i);
            visited.insert(state);
            q.push(state);
        }
        int res = 0, target = ((1<<size) - 1);
        cout << "target:" << target << endl;
        while (not q.empty())
        {
            queue<int> nx;
            cout << "steps:" << res << endl;
            while (not q.empty())
            {
                int cur = q.front();
                q.pop();
                cout << "\t, cur node:" << (cur>>20) << ", state:" << (cur&target) << endl;
                int curI = cur>>20, curV = cur&target;
                if (curV == target) return res;
                for (auto nxI:graph[curI])
                {
                    int nxState = (nxI<<20)|(curV|(1<<nxI));
                    if (visited.find(nxState) == visited.end())
                    {
                        visited.insert(nxState);
                        nx.push(nxState);
                    }
                }
            }
            ++res;
            swap(nx, q);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> graph = {
        {1,2,3},{0},{0},{0}
        //{1},{0,2,4},{1,3,4},{2},{1,2}
    };
    auto res = sol.shortestPathLength(graph);
    cout << res << endl;
    return 0;
}
