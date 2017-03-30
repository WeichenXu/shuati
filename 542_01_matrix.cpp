#include <iostream>
#include <vector>
#include <queue>

// Use BFS
// 1. enqueue all '0'
// 2. update neighbours, enqueue if it is not visited

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> directions = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };
        queue<pair<int, int>> q;
        queue<pair<int, int>> nx;
        int step = 0;
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for (int i=0; i<r; ++i){
            for (int j=0; j<c; ++j){
                if (!matrix[i][j]){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()){
            ++step;
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                // iterate neighbours
                for (int i=0; i<directions.size(); ++i){
                    int nx_r = cur.first + directions[i][0];
                    int nx_c = cur.second + directions[i][1];
                    if (nx_r >= 0 && nx_r < r && nx_c >= 0 && nx_c < c && 
                        !visited[nx_r][nx_c]){
                        visited[nx_r][nx_c] = true;
                        nx.push({nx_r, nx_c});
                        matrix[nx_r][nx_c] = step;
                    }
                }
            }
            swap(q, nx);
        }

        return matrix;
    }
};

int main(){
    vector<vector<int>> matrix = {
        {1, 0, 0, 0},
        {0, 1, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1}
    };

    Solution sol;
    sol.updateMatrix(matrix);
    for (int i=0; i<matrix.size(); ++i){
        for (int j=0; j<matrix[0].size(); ++j){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
