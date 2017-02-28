#include <iostream>
#include <vector>
#include <algorithm>

#include <math.h>

// DP
// m[i][j] == the largest local square at the present location
//

using namespace std;

class Solution{
public:
    int maximalSquare(vector<vector<char>>& matrix){
        static constexpr char zero = '0';
        int h = matrix.size();
        if (!h) return 0;
        int w = matrix[0].size();

        char res = zero;
        // iterate the matrix by row
        for (int i=0; i<h; ++i){
            for (int j=0; j<w; ++j){
                char& cur = matrix[i][j];
                if (cur-zero > 0){
                    // if the NW element also construct a square
                    int extend = 0;
                    if (i-1 >=0 && j-1 >= 0){
                        extend = matrix[i-1][j-1]-zero;
                    }
                    // whether the extended area are '1's
                    for (int k=0; k<extend; ++k){
                        if (matrix[i][j-1-k] <= zero || matrix[i-1-k][j] <= zero){
                            extend = k;
                            break;
                        }
                    }
                    cur = zero + extend + 1;
                    res = max(res, cur);
                }
            }
        }

        return pow(res-zero, 2);
    }
};

int main(){
    vector<vector<char>> board = {
        {'0','0','0', '1'},
        {'1','1','0', '1'},
        {'1','1','1', '1'},
        {'0','1','1', '1'},
        {'0','1','1', '1'}
    };
    Solution sol;
    auto res = sol.maximalSquare(board);
    cout << "The largest square is size " << res << endl;
    return 0;
}
