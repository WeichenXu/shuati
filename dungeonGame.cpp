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
    
    int calculateMinimumHP(vector<vector<int>>& dungeon){
        if (dungeon.empty() || dungeon[0].empty()){
            return 0;
        }
        int rows = dungeon.size(), cols = dungeon[0].size();
        
        vector<vector<int>> hp(rows+1, vector<int>(cols+1, INT_MIN));
        hp[rows-1][cols] = 0;
        // dp from bottom-right to up-left
        for (int i=rows-1; i>=0; --i){
            for (int j=cols-1; j>=0; --j){
                hp[i][j] = min(0, max(hp[i+1][j], hp[i][j+1])) + dungeon[i][j];
            }
        }

        return (hp[0][0] < 0) ? -hp[0][0] + 1 : 0;
    }

};

int main(){
    Solution sol;
    vector<vector<int>> dun = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    int ans = sol.calculateMinimumHP(dun);
    cout << "Ans: " << ans << endl;
}
