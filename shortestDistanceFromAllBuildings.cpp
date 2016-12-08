class Solution {
public:
    //return the min dis
    int bfs(vector<vector<int>>& grid, int i, int j, int buildIdx){
        //cout << "bfs: " << i << " "<< j << ", idx:" << buildIdx << endl;
        int minDist = -1;
        queue<pair<int, int>> steps;
        steps.emplace(i, j);
        auto walkPath = origin;
        while (!steps.empty()){
            auto cur = steps.front();
            steps.pop();
            // start walking to the next position
            for(int s=0; s<4; ++s){
                int ni = cur.first + dx[s];
                int nj = cur.second + dy[s];
                if (ni>=0 && ni<r && nj>=0 && nj<c && grid[ni][nj] == buildIdx){
                    steps.emplace(ni, nj);
                    grid[ni][nj] = buildIdx - 1;
                    // distance from build idx to all previous ones 
                    walkPath[ni][nj] = walkPath[cur.first][cur.second] + 1;
                    total[ni][nj] += walkPath[ni][nj] - 1;
                    // update the minDist
                    if (minDist < 0 || minDist > total[ni][nj]){
                        minDist = total[ni][nj];
                    }
                }
            }
        }
        return minDist;
    }
    int shortestDistance(vector<vector<int>>& grid) {
        r = grid.size(), c = grid[0].size();
        total = grid;
        origin = grid;
        int res = INT_MAX, idx = 0;
        // up, left, down, right steps
        dx ={-1, 0, 1, 0};
        dy ={0, -1, 0, 1};
        // use bfs at each position
        for (int i=0; i<r; ++i){
            for (int j=0; j<c; ++j){
                if (grid[i][j] == 1){
                    // start bfs from this building
                    res = bfs(grid, i, j, idx--);
                    if (res == -1){
                        return res;
                    }
                }
            }
        }
        return res;
    }
private:
    vector<vector<int>> total, origin;
    vector<int> dx, dy;
    int r, c;
};
