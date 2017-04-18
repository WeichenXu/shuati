#include <iostream>
#include <vector>
#include <set>
// 1. Use Kadane's algorithm to solve 2D
// 2. Max subarray no more than k

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int l=0, r=0, res = INT_MIN;
        int row = matrix.size();
        if (!row)   return 0;
        int col = matrix[0].size();

        // conduct Kadane's algo
        vector<int> nums(row,0);
        for (; l<col; ++l){
            for (r=l; r<col; ++r){
                for (int i=0; i<row; ++i){
                    nums[i] += matrix[i][r];
                }
                int tmp = max_subarray_no_more_than_k(nums, k);
                cout << "L: " << l << ", R: " << r << ", max: " << tmp << endl;  
                res = max(res, max_subarray_no_more_than_k(nums, k));
            }
            fill(nums.begin(), nums.end(), 0);
        }

        return res;
    }

//private:
    int max_subarray_no_more_than_k(vector<int>& nums, int k){
        cout << "\t nums " << endl;
        for (auto n:nums){
            cout << n << " ";
        }
        cout << endl;
        set<int> sums;
        int cur = 0, res = INT_MIN;
        for (auto n:nums){
            sums.insert(cur);
            cur += n;
            auto it = sums.lower_bound(cur-k);
            if (it == sums.end())   continue;
            res = max(res, cur - *it);
        }
        return res;
    }
};

int main(){
    vector<vector<int>> nums = {
        {5,-4,-3,4},
        {-3,-4,4,5},
        {5,1,5,-4}
    };
    int k = 3;
    Solution sol;
    auto res = sol.maxSumSubmatrix(nums, k);
    //auto res = sol.max_subarray_no_more_than_k(nums[0], k);
    cout << "Result is " << res << endl;
    return 0;
}
