#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int size = position.size();
        vector<pair<int, double>> time(size, {0, 0.0});
        for (int i=0; i<size; ++i)
        {
            double t = double(target-position[i])/double(speed[i]);
            time[i] = {position[i],t};
        }
        sort(time.begin(), time.end(), [](const auto&l, const auto& r){return l.first < r.first || (l.first == r.first and l.second < r.second);});
        for (auto& t:time)   cout << t.first << "->" << t.second << endl;
        double curMax = double(-pow(10,7));
        int res = 0;
        for (auto it=time.rbegin(); it != time.rend(); ++it)
        {
            if (it->second > curMax)
            {
                ++res;
                curMax = it->second;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> pos = {0,4,4,2};
    vector<int> speed= {2,1,2,3};
    auto res = sol.carFleet(10, pos, speed);
    cout << res << endl;

}
