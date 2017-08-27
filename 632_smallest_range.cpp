#include <iostream>
#include <vector>
#include <queue>

// Sliding Window
// Keep a sorted iterator to cur in vector<int>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int left = INT_MAX, right = INT_MIN;
        // construct a min-heap store k nums
        using pair_t = std::pair<vector<int>::iterator, int>;
        auto cmp = [](const pair_t l, const pair_t r){return *(l.first) > *(r.first);};
        priority_queue<pair_t, vector<pair_t>, decltype(cmp)> q(cmp);
        for (int i=0; i<nums.size(); ++i){
            auto it = nums[i].begin();
            left = min(left, *it);
            right = max(right, *it);
            q.push({ it, i});
        }

        // slide against all nums
        vector<int> res = {left, right};
        int min_gap = right - left;
        auto prev = q.top();
        while(next(prev.first) != nums[prev.second].end()){
            q.pop();
            q.push({ ++(prev.first), prev.second});
            left = *q.top().first;
            right = max(right, *prev.first);
            prev = q.top();
            if (min_gap > (right-left)){
                min_gap = right - left;
                res = {left, right};
            }
        }

        return res;
    }
};

int main(){
    vector<vector<int>> nums = {
        {4,10,15,24,26}, 
        {0,9,12,20}, 
        {5,18,22,30}
    };
    Solution sol;
    auto res = sol.smallestRange(nums);
    cout << "start: " << res[0] << ", end:" << res[1] << endl;
    return 0;
}
