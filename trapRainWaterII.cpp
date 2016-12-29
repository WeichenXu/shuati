#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// use a priority_queue to form the circle around the center
// conduct bfs until all nodes are traversed

class Solution{
public:
    class cell{
    public:
        int row_{0},col_{0};
        int height_{0};
        cell (int row, int col, int height): row_(row), col_(col), height_(height){}
        ~cell(){};
    };
    int trapRainWater(vector<vector<int>>& height){
        if (height.size() <= 2 || height[0].size() <= 2){
            return 0;
        }
        int rows = height.size(), cols = height[0].size();
        
        auto cell_cmp = [](const cell& l, const cell& r){return l.height_ > r.height_;};
        using priority_queue_t = priority_queue<cell, std::vector<cell>, decltype(cell_cmp)>;
        priority_queue_t q(cell_cmp);

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        // add the borders into the queue
        for (int i=0; i<rows; ++i){
            visited[i][0] = true;
            visited[i][cols-1] = true;
            q.emplace(cell(i, 0, height[i][0]));
            q.emplace(cell(i, cols-1, height[i][cols-1]));
        }
        for (int i=1; i<cols-1; ++i){
            visited[0][i] = true;
            visited[rows-1][i] = true;
            q.emplace(cell(0, i, height[0][i]));
            q.emplace(cell(rows-1, i, height[rows-1][i]));
        }

        // do bfs with smallest cell
        int sum = 0;
        // dirs: up, down, left, right
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            auto s = q.top();
            q.pop();
            for (int i=0; i<4; ++i){
                int r = s.row_ + dirs[i].first, c = s.col_ +dirs[i].second;
                if (r>=0 && r<rows && c>=0 && c<cols && !visited[r][c]){
                    q.emplace( cell( r, c, max(height[r][c], s.height_) ) );
                    sum += max(0, s.height_ - height[r][c]);
                    visited[r][c] = true;
                }
            }
        }
        
        return sum;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> map = {{1,4,3,1,3,2}, {3,2,1,3,2,4}, {2,3,3,2,3,1}};
    cout << "Ans: " << sol.trapRainWater(map) << endl;
}
