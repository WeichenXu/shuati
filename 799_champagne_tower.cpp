#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        //BFS
        vector<double> level(1, static_cast<double>(poured));
        for (int i=1; i<=query_row; ++i)
        {
            vector<double> nx(i+1, 0.0);
            double remain = 0.0;
            for (int j=0; j<level.size(); ++j)
            {
                if (level[j] >= 1.0)
                {
                    auto over = (level[j]-1.0)/2.0;
                    nx[j] += over;
                    nx[j+1] += over;
                    remain += over*2.0;
                }
            }
            if (remain == 0.0)  return 0.0;
            swap(nx, level);
        }
        return min(0.0,level[query_glass]);
    }
};

int main()
{
    Solution sol;
    auto res = sol.champagneTower(10, 4,3);
    cout << res << endl;
}
