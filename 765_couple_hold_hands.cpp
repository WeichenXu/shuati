#include <iostream>
#include <vector>

using namespace std;

// 1. Construct and correct cycles
class Solution {
public:
    inline int partner(int i)
    {
        return i%2 == 0 ? i+1:i-1;
    }
    int minSwapsCouples(vector<int>& row) {
        int len = row.size(), res = 0;
        // mapping person to seat
        vector<int> pos(len, 0);
        for (int i=0; i<len; ++i)
        {
            pos[row[i]] = i;
        }
        for (int i=0; i < len; i+=2)
        {
            for (int j=partner(pos[partner(row[i])]); i!=j; j=partner(pos[partner(row[i])]))
            {
                swap(row[i], row[j]);
                swap(pos[row[i]], pos[row[j]]);
                ++res;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> row = {0,2,1,3};
    auto res = sol.minSwapsCouples(row);
    cout << res << endl;
}
