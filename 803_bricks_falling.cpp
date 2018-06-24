#include <iostream>
#include <vector>

// find new connected bricks in reverse way
using namespace std;

class Solution {
    /* DFS
private:
    vector<vector<int>> m_dirs = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    template<typename T, typename U>
    int dfs(int rows, int cols, int i, int j, T& visited, U& grid)
    {
        if (i<0 || i>=rows || j<0 || j >= cols || visited[i][j] || grid[i][j] <= 0)  return 0;
        visited[i][j] = true;
        grid[i][j] = -1;
        int res = 1;
        for (const auto& d:m_dirs)
        {
            res += dfs(rows, cols, i+d[0], j+d[1], visited, grid);
        }
        return res;
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        // 1. remove all hits
        for (const auto& hit : hits)
        {
            if (grid[hit[0]][hit[1]])   grid[hit[0]][hit[1]] = -2;
        }
        // 2. mark all sticked bricks as -1
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i=0; i<cols; ++i)  dfs(rows, cols, 0, i, visited, grid);
        for (const auto &r:grid)
        {
            for (const auto c:r)    cout << c << " ";
            cout << endl;
        }
        vector<int> res(hits.size(), 0);
        for (int i=hits.size()-1; i>=0; --i)
        {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) continue;
            grid[r][c] = 1;
            bool newConnect = false;
            for (const auto& d:m_dirs)
            {
                int nxR = d[0]+r, nxC = d[1]+c;
                if ((nxR >= 0 and nxR < rows and nxC >= 0 and nxC < cols and grid[nxR][nxC] == -1) or (not r))
                {
                    newConnect = true;
                    break;
                }
            }
            if (newConnect)
            {
                for (auto& r:visited) fill(r.begin(), r.end(), false);
                res[i] = dfs(rows, cols, hits[i][0], hits[i][1], visited, grid)-1;
            }
            for (const auto &r:grid)
            {
                for (const auto c:r)    cout << c << " ";
                cout << endl;
            }
        }
        return res;
    }
    */

    // union and find
public:
    int Find(int idx)
    {
        if (m_parent[idx] == idx)   return idx;
        int p = Find(m_parent[idx]);
        m_parent[idx] = p;
        return p;
    }
    void Union(int l, int r)
    {
        int lRoot = Find(l), rRoot = Find(r);
        if (lRoot != rRoot)
        {
            if (rRoot < m_c)
            {
                m_parent[lRoot] = rRoot;
                m_cnt[rRoot] += m_cnt[lRoot];
                m_cnt[lRoot] = 0;
            }
            else
            {
                m_parent[rRoot] = lRoot;
                m_cnt[lRoot] += m_cnt[rRoot];
                m_cnt[rRoot] = 0;
            }
        }
    }
    vector<int> m_parent, m_cnt;
    vector<pair<int, int>> m_directions = {
        {-1,0}, {0,-1},{1,0},{0,1}
    };
    int m_r, m_c;
    inline int to1d(int i, int j) {return i*m_c + j;} 
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        m_r = grid.size(), m_c = grid[0].size();
        m_parent.resize(m_r*m_c, -1);
        m_cnt.resize(m_r*m_c, 0);
        // erase all hitted bricks
        for (const auto& hit:hits)
        {
            if (grid[hit[0]][hit[1]] == 1) grid[hit[0]][hit[1]] = -1;
        }
        auto getNeighbors = [this, &grid](int i, int j){
            vector<pair<int, int>> neighbors;
            for (auto& dir:m_directions)
            {
                int nxI = i+dir.first, nxJ = j+dir.second;
                if (nxI >= 0  and nxI < m_r and nxJ >= 0 and nxJ < m_c and grid[nxI][nxJ] == 1)
                {neighbors.push_back({nxI,nxJ});}
            }
            return neighbors;
        };
        auto addBrick = [&](int i, int j)
        {
            m_cnt[to1d(i, j)] = 1;
            auto neighbors = getNeighbors(i, j);
            for (auto& neigh:neighbors)
            {
                if (m_parent[to1d(neigh.first, neigh.second)] != -1)   Union(to1d(i, j), to1d(neigh.first, neigh.second));
            }
        };
        auto getSticked = [&](){
            int res = 0;
            for (int i=0; i<m_c; ++i){
                res += m_cnt[to1d(0, i)];
            }
            return res;
        };
        // init region
        for (int i=0; i<m_r; ++i)
        {
            for (int j=0; j<m_c; ++j){  
                m_parent[to1d(i, j)] = to1d(i, j);
                if (grid[i][j] == 1)    
                {
                    addBrick(i, j);
                }
            }
        }
        // reverse add back
        vector<int> res(hits.size(), 0);
        int lastSum = getSticked(); 
        for (int i=hits.size()-1; i>=0; --i)
        {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == -1)
            {
                grid[r][c] = 1;
                addBrick(r, c);
            }
            auto curSum = getSticked();
            res[i] = max(0, curSum - lastSum-1);
            swap(lastSum, curSum);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1,1,1},
        {0,1,0},
        {0,0,0},
    };
    vector<vector<int>> hits = {
        //{0,2}, {2,0},{0,1},{1,2}
        {0,2}, {2,0},{0,1}
    };
    Solution sol;
    auto res  = sol.hitBricks(grid, hits);
    for (auto r:res)    cout << r << " ";
    cout << endl;
    return 0;
}
