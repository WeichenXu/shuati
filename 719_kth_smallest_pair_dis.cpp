#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/* TLE, n^2lgn
class Solution {
public:
    struct node{
        int m_abs;
        int m_start;
        int m_end;
        node (int abs, int start, int end): m_abs(abs), m_start(start), m_end(end)
        {}
    };
    int smallestDistancePair(vector<int>& nums, int k) {
        // 1. sort nums
        // 2. find kth smallest like merge k sorted list
        sort(nums.begin(), nums.end());
        auto cmp = [](const auto& l, const auto& r)
        {
            return l.m_abs > r.m_abs;
        };
        // build min_heap
        priority_queue<node, vector<node>, decltype(cmp)> minHeap(cmp);
        for (int i=1; i<nums.size(); ++i)
        {
            minHeap.push({nums[i]-nums[i-1], i-1, i});
        }
        for (int i=0; i<k-1; ++i)
        {
            auto& n = minHeap.top();
            if (n.m_end < nums.size()-1)
            {
                minHeap.push({nums[n.m_end+1]-nums[n.m_start], n.m_start, n.m_end+1});
            }
            minHeap.pop();
        }
        return minHeap.top().m_abs;
    }
};
*/

// Binary search
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = INT_MAX, hi = nums.back()-nums.front();
        for (int i=1; i<nums.size(); ++i)
        {
            lo = min(lo, nums[i]-nums[i-1]); 
        }
        while (lo < hi)
        {
            int mid = lo+(hi-lo)/2;
            // get the count of diff pair <= mid
            int count = 0;
            for (int i=1; i<nums.size(); ++i)
            {
                int start = i-1;
                while (start >= 0 and nums[i] - nums[start] <= mid)
                {
                    --start;
                    ++count;
                }
            }
            if (count >= k) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,3,1};
    auto res = sol.smallestDistancePair(nums, 2);
    cout << res << endl;
    return 0;
}
