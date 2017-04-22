#include <iostream>
#include <vector>

// 1. sum the elements in the 2D
// 2. query the 2D region:
//    (r1, c1, r2, c2) = (r2, c2) + (r1-1, c1-1) - (r1-1, c2) - (r2, c1-1)
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sums_;
public:
    NumMatrix(vector<vector<int>> matrix) {
        int r = matrix.size();
        if (!r) return;
        int c = matrix[0].size();
        sums_.resize(r+1, vector<int>(c+1, 0));
        // sum the elements by row
        for (int i=0; i<r; ++i){
            int row_sum = 0;
            for (int j=0; j<c; ++j){
                row_sum += matrix[i][j];
                sums_[i+1][j+1] = sums_[i][j+1] + row_sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (sums_.empty() || row1 > row2 || row1 < 0 || row2 >= sums_.size()){
            return 0;
        }
        if (col1 > col2 || col1 < 0 || col2 >= sums_[0].size()){
            return 0;
        }
        return sums_[row2+1][col2+1] + sums_[row1][col1] - sums_[row1][col2+1] - sums_[row2+1][col1];
    }
};

/**
 *  * Your NumMatrix object will be instantiated and called as such:
 *   * NumMatrix obj = new NumMatrix(matrix);
 *    * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 *     */

int main(){
    vector<vector<int>> nums = {
        {1, 1, 1, 1, 1,},
        {1, 1, 1, 1, 1,},
        {1, 1, 1, 1, 1,},
    };
    NumMatrix obj(nums);
    int row1 = 0, row2 = 1;
    int col1 = 0, col2 = 3;
    auto sum =  obj.sumRegion(row1, col1, row2, col2);
    cout << "Region sum is " << sum << endl;
    return 0;
}
