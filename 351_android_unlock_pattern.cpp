#include <iostream>
#include <vector>

#include <vector>

// DFS the keyboard 
// 1. group {1,3,7,9} has same number of path
//    group {2,4,6,8} , {5}
// 2. use skip array to represent the key we could skip during dfs

using namespace std;

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        if (m == 0 && n == 0){
            return 1;
        }
        vector<bool> visited(9, false);
        vector<int> row(10, 0);
        skip.resize(10, row);
        skip[1][3] = skip[3][1] = 2;
        skip[7][9] = skip[9][7] = 8;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = 
        skip[3][7] = skip[7][3] = skip[6][4] = skip[4][6] = 5;
       
        dfs(visited, 1, 1, m, n, 4);
        dfs(visited, 1, 2, m, n, 4);
        dfs(visited, 1, 5, m, n, 1);

        return result;
    }
private:
    int result{0};
    vector<vector<int>> skip;
    void dfs(vector<bool>& visited, int len, int cur, int m, int n, int t){
        // if path is too long 
        if (len > n)   return;
        visited[cur] = true;
        if (len >= m)   result += t;
        
        // go to the next key
        for (int i=1; i<=9; ++i){
            if (!visited[i] && (!skip[cur][i] || visited[skip[cur][i]]) )
                dfs(visited, len+1, i, m, n, t);
        }
        visited[cur] = false;
    }
};

int main(){
    Solution sol;
    int m = 2, n = 4;
    auto res = sol.numberOfPatterns(m, n);
    cout << "Total pattern: " << res << endl;
    return 0;
}
