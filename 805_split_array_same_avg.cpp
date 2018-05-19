#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

// This is NP, https://leetcode.com/problems/split-array-with-same-average/discuss/120667/C++-Solution-with-explanation-early-termination-(Updated-for-new-test-case)

using namespace std;

// DP
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        // kSum = k*avg = k*totalSum/n, where k*totalSum%n == 0
        // early pruning
        const int sum = accumulate(A.begin(), A.end(), 0);
        int size = A.size(), k = size/2;
        bool canBeSplit = false;
        for (int i=1; i<=k and not canBeSplit; ++i)
        {
            if (sum*i%size == 0)
            {
                canBeSplit = true;
            }
        }
        if (not canBeSplit) return false;
        // enumerate all sum[i][j] combination, choose any i number out of A[0,j]
        vector<unordered_set<int>> dp(k+1);
        dp[0].insert(0);
        for (const auto num:A)
        {
            for (int i=k; i>=1; --i)
            {
                for (const auto preSum:dp[i-1])
                {
                    dp[i].insert(preSum + num);
                }
            }
        }
        for (const auto& s:dp)
        {
            for (auto i:s)
            {
                cout << i << " ";
            }
            cout <<  endl;
        }
        for (int i=1; i<=k; ++i)
        {
            if (sum*i%size == 0 and dp[i].find(sum*i/size) != dp[i].end()) 
            {
                cout << i << ", " << sum*k/size << endl;
                return true;
            }
        }
        return false;
    }
};
/* Bacttracking TLE
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        const auto sum = accumulate(A.begin(), A.end(), 0);
        const auto size = A.size();
        double avg = double(sum)/size;
        cout << avg << endl;
        // if combination of A could sum to target
        return backTracking(A, 0, 0, 0, avg);
    }
    bool backTracking(const vector<int>& nums, int sum, int idx, int n, const double avg)
    {
        if (idx >= nums.size())   return false;
        auto avgMatch = [&](int sum, int n)
        {
            if (sum && double(sum)/n == avg && n<nums.size())
            {
                cout << sum << ", "<< n  << endl;
                return true;
            }
            return false;
        };
        if (avgMatch(sum, n) || avgMatch(sum+nums[idx], n+1))   return true;
        return backTracking(nums, sum, idx+1, n, avg) || backTracking(nums, sum+nums[idx], idx+1, n+1, avg);
    }
};
*/

int main()
{
    Solution sol;
    //vector<int> nums = {1,2,3,4,5,6,7,8};
    //vector<int> nums = {4,4,4,4,4,4,5,4,4,4,4,4,4,5};
    vector<int> nums = {18,10,5,3};
    auto res = sol.splitArraySameAverage(nums);
    cout << res << endl;
    return 0;
}
