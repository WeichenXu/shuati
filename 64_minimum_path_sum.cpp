#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        for (int i=0; i<rows; ++i)
        {
            for (int j=0; j<cols; ++j)
            {   
                int prev = 0;
                if (i && j)   prev = min(grid[i-1][j], grid[i][j-1]);
                else if (j)   prev = grid[i][j-1];
                else if (i)   prev = grid[i-1][j];
                grid[i][j] += prev;
            }
        }

        return grid[rows-1][cols-1];
    }
};

int main(){
    vector<vector<int>> grid = {
        {1,1,0,1},
        {0,0,1,1},
        {0,0,0,0},
        {0,1,1,1}
    };
    Solution sol;
    cout << sol.minPathSum(grid) << endl;
    for (auto & rows:grid){
        for (auto num:rows){
            cout << num << " ";
        }
        cout << endl;
    }
}
