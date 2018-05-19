#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> m;
        for(const auto num:nums) ++m[num];
        int size = m.size();
        int lastTaken = 0, lastNotTaken = 0;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (it == m.begin())
            {
                lastTaken = it->first * it->second;
            }
            else
            {
                int tmp= max(lastTaken, lastNotTaken);
                int pre = prev(it)->first;
                lastTaken = (it->first * it->second) + (pre == (it->first - 1)?lastNotTaken:tmp);
                lastNotTaken = tmp;
            }
            cout << lastTaken << ", " << lastNotTaken << endl;
        }
        return max(lastTaken, lastNotTaken);
    }
};

int main()
{
    //vector<int> nums = {2,2,3,3,3,4};
    vector<int> nums = {1,6,3,3,8,4,8,10,1,3};
    Solution sol;
    auto res = sol.deleteAndEarn(nums);
    cout << res << endl;
    return 0;
}
