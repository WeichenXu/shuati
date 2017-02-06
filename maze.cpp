#include <iostream>
#include <vector>
#include <vector>

// do dfs/bfs from start to destination
// dfs: record the visited path
// bfs: keep the queue of current corners

using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        maze_ = move(maze);
        r_ = maze_.size();
        if (!r_){
            return false;
        }
        c_ = maze_[0].size();

        return dfs(start, destination); 
    }
 
private:
    vector<vector<int>> maze_;
    int r_{0},c_{0};
    
    /* utility function */
    // recursive by dfs
    // return 0: reach the dst and stopped
    // return 1: can not be reached
    bool dfs(vector<int> cur, vector<int>& dst){
        int r = cur[0], c = cur[1];
        //cout << "Visiting " << r << ", " << c << endl;
        if (r == dst[0] && c == dst[1]){
            return true;
        }
        if (maze_[r][c] == -1){
            return false;
        }
        maze_[r][c] = -1;
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0; i<4; ++i){
            //cout << "From " << r << ", " << c << ", go to " << directions[i][0] << ", " << directions[i][1] << endl;
            auto nx = goToEnd(cur, directions[i]);
            //cout << "Result: " << nx[0] << ", " << nx[1] << endl;
            if (dfs(nx, dst)){
                return true;
            }
        }
        return false;
    }

    vector<int> goToEnd(const vector<int>& cur, const vector<int>& direct){
        int nx_i=direct[0], nx_j=direct[1];
        int i=cur[0] + nx_i, j=cur[1] + nx_j;
        while(i>=0 && i<r_ && j>=0 && j<c_ && maze_[i][j]!=1){
            i += nx_i, j += nx_j;
        }
        i -= nx_i, j -= nx_j;
        return {i, j};
    }
};

int main(){
    Solution sol;
    vector<vector<int>> maze = {
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,1,0},
        {1,1,0,1,1},
        {0,0,0,0,0}
    };
    vector<int> start = {0,4}, dst = {4,4};
    cout << "The solution find the path: " << sol.hasPath(maze, start, dst) << endl;
    return 0;
}
