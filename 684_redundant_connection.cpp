#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> parent;
    int Find(int i)
    {
        if (parent[i] == i) {return i;}
        parent[i] = Find(parent[i]);
        return parent[i];
    }
    bool Union(int left, int right)
    {
        int lRoot = Find(left), rRoot = Find(right);
        if (lRoot!=rRoot) {
            parent[lRoot] = rRoot;
            return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        parent.resize(N);
        for (int i=0; i<N; ++i){parent[i] = i;}
        vector<int> res;
        for (const auto& edge:edges)
        {
            if (not Union(edge[0]-1, edge[1]-1))
            {
                res = edge;
                break;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main()
{
    vector<vector<int>> edges = {
        {1,2},{2,3},{3,4},{1,4},{1,5}
    };
    Solution sol;
    auto res = sol.findRedundantConnection(edges);
    cout << res[0] << "->" << res[1] << endl;
    return 0;
}
