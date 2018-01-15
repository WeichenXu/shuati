#include <iostream>
#include <iterator>
#include <vector>
#include <set>

using namespace std;

// 1. Multiset a store flower positions
// 2. Multiset b store flower intervals
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> positions;
        vector<bool> intervals(flowers.size(), false); 
        for (const auto f:flowers)
        {
            // insert flower and update intervals
            auto p = positions.insert(f);
            std::vector<int> toAddIntervals;
            if (p.first != positions.begin())
            {
                toAddIntervals.push_back(f - *prev(p.first));
            }
            if (next(p.first) != positions.end())
            {
                toAddIntervals.push_back(*next(p.first) - f);
            }
            for (const auto i:toAddIntervals)
            {
                cout << "insert interval " << i-1 << endl;
                intervals[i-1] = true;
            }
            // check if k slots find
            if (intervals[k])
            {
                return positions.size();
            }
        }
        return -1;
    }

};

int main()
{
    Solution sol;
    std::vector<int> flowers = {1,3,2};
    int k = 4;
    auto res = sol.kEmptySlots(flowers, k);
    std::cout << res << std::endl;
    return 0;
}
