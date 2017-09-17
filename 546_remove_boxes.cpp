#include <iostream>
#include <vector>
#include <algorithm>

//  dp[i][j][k] : max points with k same boxes[i] on left

using namespace std;

class Solution {
public:
    int helper(vector<int>& boxes, vector<vector<vector<int>>>& dp, int i, int j, int k)
    {
        if (i>j)    return 0;
        if (dp[i][j][k] > 0)    return dp[i][j][k];
        // all same dp[i...] should be grouped together
        for (; i+1<=j && boxes[i+1] == boxes[i]; ++i, ++k){}
        // remove boxes[i]
        int res = (k+1)*(k+1) + helper(boxes, dp, i+1, j, 0);
        for (int m=i+1; m<=j; ++m)
        {
            if (boxes[m] == boxes[i])
            {
                res = max(res, helper(boxes, dp, i+1, m-1, 0) + helper(boxes, dp, m, j, k+1));
            }
        }
        dp[i][j][k] = res;
        return res;
    }
    int removeBoxes(vector<int>& boxes) {
        int len = boxes.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(len, vector<int>(len)));
        return helper(boxes, dp, 0, len-1, 0);
    }
};

int main(){
    vector<int> box = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    Solution sol;
    cout << sol.removeBoxes(box) << endl;
    return 0;
}
