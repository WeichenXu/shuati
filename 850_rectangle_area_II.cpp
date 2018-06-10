#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    struct op{
        int m_sign{0}, m_y1{0}, m_y2{0};
    };
    int rectangleArea(vector<vector<int>>& rectangles) {
        map<int, vector<op>> ops;
        for (const auto &rec:rectangles)
        {
            ops[rec[0]].push_back({1, rec[1], rec[3]});
            ops[rec[2]].push_back({-1, rec[1], rec[3]});
        }

        map<int, multiset<int>> ys;
        int preX = INT_MAX, preY = 0;
        long ares = 0;
        for (auto& p:ops)
        {
            int x = p.first;
            cout << "Iterate x:" << x << endl;
            const auto& curOps = p.second;
            for (auto& o:curOps)
            {
                if (o.m_sign == 1)  ys[o.m_y1].insert(o.m_y2);
                if (o.m_sign == -1)  
                {
                    auto it = ys.find(o.m_y1);
                    it->second.erase(it->second.find(o.m_y2));
                    if (it->second.empty()) ys.erase(it);
                }
            }
            // calcu preY
            cout << "Calc next Ys: " << endl;
            int nextY = 0, curY=INT_MIN;
            auto it = ys.begin();
            while (it != ys.end())
            {
                int y1 = it->first;
                int y2 = *(it->second.rbegin());
                cout << "\t" << y1 << "->" << y2 << endl;
                if (y1 > curY)
                {
                    nextY += y2 - y1;
                    curY = y2;
                }
                else if(y2 > curY)
                {
                    nextY += y2-curY;
                    curY = y2;
                }
                ++it;
            }

            if (preX != INT_MAX)    ares += (long)preY * (long)(x-preX);
            preX = x;
            preY = nextY;
            cout << "ys: " << nextY << endl;
        }
        ares %= static_cast<long>(pow(10,9) + 7);
        return ares;
    }
};

int main()
{
    vector<vector<int>> rectangles = {
        //{0,0,2,2},{1,0,2,3},{1,0,3,1}
        //{0,0,1000000000,1000000000}
        {0,0,3,3}, {2,0,5,3}, {1,1,4,4}
    };
    Solution sol;
    auto res = sol.rectangleArea(rectangles);
    cout << res << endl;
    return 0;
}
