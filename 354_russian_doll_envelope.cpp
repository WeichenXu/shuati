#include <iostream>
#include <vector>
#include <algorithm>

//  1. sort the envelopes according to width
//  2. compute longest increasing len of each subarray

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        using envelope_t = pair<int, int>;
        // 1. sort the envelopes, ascending order in width
        auto envelope_less_width = [](const envelope_t& left, const envelope_t& right){
            return (left.first < right.first) || (left.first == right.first && left.second >= right.second);
        };
        sort(envelopes.begin(), envelopes.end(), envelope_less_width);

        // 2. compute the longest increasing subsequence
        int dp[envelopes.size()];
        int len = 0;
        for (const auto& elp:envelopes){
            int  i = lower_bound(dp, len, elp.second);
            i = max(0, i);
            dp[i] = elp.second;
            if (i == len)   ++len;
        }
        return len;
    }

private:
    // return the lower_bound of array<int>
    int lower_bound(int* dp, int len, int target){
        int lo = 0, hi = len-1;
        if (!len)    return hi;
        while (lo < hi){
            int mid = (lo + hi) >> 1;
            if (dp[mid] >= target)
                hi = mid;
            else
                lo = mid+1;
        }
        return dp[lo] < target ? len : lo; 
    }
};

int main(){
    vector<pair<int, int>> envelopes = {
        {1,1},
        {1,2},
        {1,3},
        {2,2},
        {3,2},
        {4,3}
    };
    Solution sol;
    auto res = sol.maxEnvelopes(envelopes);
    cout << "Result: " << res << endl;
}
