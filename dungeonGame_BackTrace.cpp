#include <iostream>
#include <vector>
// Initial solution, dp with 
// 1. the minimum requirement along this path 
// 2. the remiaining hp
// ABOVE solution is out of mind, choose backtrace instead
// go right or down

using namespace std;

class Solution{
public:
    void backTrace(vector<vector<int>>& dungeon, int i, int j, int request, int remain){
        int demon = dungeon[i][j];
        request = min(request, request + remain + demon);
        remain = max(0, remain + demon);

        if (i == rows_-1 && j == cols_-1 ){
            leastHP_ = min(leastHP_, -request+1);
            return;
        }
        
        // go right
        if (j < cols_-1){
            backTrace(dungeon, i, j+1, request, remain);    
        }
        // go left
        if (i < rows_-1){
            backTrace(dungeon, i+1, j, request, remain);
        }
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon){
        if (dungeon.empty() || dungeon[0].empty()){
            return 0;
        }
        rows_ = dungeon.size(), cols_ = dungeon[0].size();
        
        // start the back trace
        backTrace(dungeon, 0, 0, 0, 0);

        return leastHP_;
    }
private:
    int cols_{0},rows_{0};
    int leastHP_{INT_MAX};
};

int main(){
    Solution sol;
    vector<vector<int>> dun = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    int ans = sol.calculateMinimumHP(dun);
    cout << "Ans: " << ans << endl;
}
