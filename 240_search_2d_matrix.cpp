#include <iostream>
#include <vector>

using namespace std;
// o(m+n)
// remove one line/row each time

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())    return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int i = 0, j = cols-1;

        while(i < rows && j >= 0)
        {
            int val = matrix[i][j];
            if (val == target)  return true;
            else if (val < target)
            {
                ++i;
            }
            else
            {
                --j;
            }
        }

        return false;
    }
};

int main(){
    vector<vector<int>> nums = {
        {1, 4, 7},
        {2, 10, 15},
        {12, 13, 16}
    };

    Solution sol;
    cout << sol.searchMatrix(nums, 2) << endl;
    cout << sol.searchMatrix(nums, 16) << endl;
    cout << sol.searchMatrix(nums, -1) << endl;
}
