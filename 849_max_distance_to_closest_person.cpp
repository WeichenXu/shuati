#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int size = seats.size();
        seats.push_back(1);
        int lastOne = -1, res = 0;
        for (int i=0; i<=size; ++i)
        {
            if (seats[i])
            {
                int curDis = (i - lastOne)/2;
                if (lastOne == -1)  curDis = i;
                else if (i == size) curDis = i - lastOne - 1;
                lastOne = i;
                res = max(res, curDis);
            }
        }
        return res;
    }
};


int main()
{
    Solution sol;
    vector<int> nums = {1,1,0,0,1,0,1};
    auto res = sol.maxDistToClosest(nums);
    cout << res << endl;
    return 0;
}
