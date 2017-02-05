#include <iostream>
#include <vector>
#include <queue>

// 1. consider the problem seperately
// 2. use bfs to extend
using namespace std;

class Solution{
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix){
        vector<pair<int, int>> res;
        int atlanMask = 0b01, pacifMask = 0b10;

        // 1. get the infromation of the matrix
        row = matrix.size();
        if (!row){
            return res;
        }
        col = matrix[0].size();
        vector<vector<int>> connected(row, vector<int>(col, 0));


        // 2. do bfs for atlantic & pacific
        bfs(connected, matrix, 0, 0, pacifMask);
        bfs(connected, matrix, row-1, col-1, atlanMask);
        
        // 4. find the overlapping for both ocean
        for (int i=0; i<row; ++i){ 
            for (int j=0; j<col; ++j){
                if (connected[i][j] == 3){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }

private:
    int row{0}, col{0};

    void bfs(vector<vector<int>>& connected, vector<vector<int>>& matrix, int start_row, int start_col, int mask){
        vector<vector<int>> directions = {{0,1}, {0,-1},{-1,0},{1,0}};
        queue<pair<int, int>> nodes;
        for(int i=0; i<col; ++i){
            connected[start_row][i] |= mask;
            nodes.push({start_row,i});
        }
        for(int j=0; j<row; ++j){
            connected[j][start_col] |= mask;
            nodes.push({j, start_col});
        }
        while (!nodes.empty()){
            auto cur = nodes.front();
            nodes.pop();
            int i = cur.first, j = cur.second, h = matrix[i][j];
            for (int d=0; d<4; ++d){
                int nx_i = i+directions[d][0], nx_j = j+directions[d][1];
                if (nx_i >= 0 && nx_i < row && nx_j >= 0 && nx_j < col && 
                        matrix[nx_i][nx_j] >= h && !(connected[nx_i][nx_j] & mask)){
                    connected[nx_i][nx_j] |= mask;
                    nodes.push({nx_i, nx_j});
                }
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };

    Solution sol;
    auto res = sol.pacificAtlantic(matrix);
    for (auto& p:res){
        cout << p.first << ", " << p.second << endl;
    }

    return 0;
}
