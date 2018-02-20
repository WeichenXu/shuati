#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.empty())
        {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        // BFS with connecting vertex
        struct node{
            int depth;
            int r;
            int c;
        };
        auto cmp = [](const auto& l, const auto& r){
            return l.depth > r.depth;
        };
        priority_queue<node, vector<node>, decltype(cmp)> edges(cmp);
        edges.push({grid[0][0], 0, 0});
        vector<pair<int,int>> directions= {{0,1},{0,-1},{-1,0},{1,0}};
        int maxD = 0;
        while(not edges.empty())
        {
            auto& n = edges.top();
            auto curD = n.depth;
            maxD = max(maxD, curD);
            int r = n.r, c = n.c;
            cout << curD << "\t" << r << "\t" << c << endl;
            grid[r][c] = -1;
            edges.pop();
            if (r == row-1 && c == col-1)
            {
                break;
            }
            for (auto& d:directions)
            {
                int nx_r = r + d.first;
                int nx_c = c + d.second;
                if (nx_r >= 0 && nx_r < row && nx_c >=0 && nx_c < col && grid[nx_r][nx_c] >= 0)
                {
                    edges.push({grid[nx_r][nx_c], nx_r, nx_c});
                }
            }
        }
        return maxD;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0,1,2,3,4},
        {24,23,22,21,5},
        {12,13,14,15,16},
        {11,17,18,19,20},
        {10,9,8,7,6}
    };
    cout << sol.swimInWater(grid) << endl;
}
