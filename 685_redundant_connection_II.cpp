#include <iostream>
#include <vector>

using namespace std;
// case 1:
//   one node has two parent
//   special case: [[1,2],[2,3],[3,4],[4,1],[1,5]]
//
// case 2:
//   cycle

class Solution {
public:
    vector<int> parent;
    vector<int> height;
    int Find(int i)
    {
        if (parent[i] == i) {return i;} 
        parent[i] = Find(parent[i]);
        return parent[i];
    }
    bool Union(int left, int right)
    {
        int lRoot = Find(left), rRoot = Find(right);
        int lHeight = height[lRoot], rHeight = height[rRoot];
        if (lRoot != rRoot)
        {
            if (lHeight > rHeight)
            {
                parent[rRoot] = lRoot;
                ++height[rRoot];
            }
            else
            {
                parent[lRoot] = rRoot;
                ++height[lRoot];
            }
            return false;
        }
        return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // 1. build graph
        // 2. whose in-degree > 1, mark as candidates
        // 3. detect cycle
        vector<int> res, candA, candB;
        int N = edges.size();
        parent.assign(N,-1);
        height.assign(N,0);
        // 1. find candidates
        for (auto& edge:edges)
        {
            int src = edge[0]-1, dst = edge[1]-1;
            if (parent[dst] >= 0)
            {
                candA = {parent[dst]+1, dst+1};
                candB = edge;
                // erase candB
                edge[1] = 0;
            }
            parent[dst] = src;
        }
        for (int i=0; i<N; ++i)
        {
            parent[i] = i;
        }
        cout << candA[0] << "->" << candA[1] <<endl;
        cout << candB[0] << "->" << candB[1] <<endl;
        for (const auto& edge:edges)
        {
            int src = edge[0]-1, dst = edge[1]-1;
            if (not edge[1]) continue;
            if (Union(src, dst))
            {
                if (candA.empty()) return edge;
                else return candA;
            }
        }
        return candB;
    }
};

int main()
{
    vector<vector<int>> edges={
        {1,5},{3,2},{2,4},{4,5},{5,3}
    };
    Solution sol;
    auto res = sol.findRedundantDirectedConnection(edges);
    cout << res[0] << "->" << res[1] << endl;
    return 0;
}
