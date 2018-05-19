#include <iostream>
#include <vector>

// 1. sort with end time
// 2. dp with lower_bound
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        auto cmp = [](const auto& l, const auto& r){
            return l[1] < r[1] || (l[1] == r[1] && l[0] < r[0]);
        };
        sort(courses.begin(), courses.end(), cmp);
        // max-course -> min-len
        vector<int> lens;
        for (const auto& course:courses)
        {
            int size = lens.size();
            int curLen = course[0], curEnd = course[1];
            for (int i=size; i>=0; --i)
            {
                int preLen = i-1>=0 ? lens[i-1]: 0;
                if (preLen + curLen <= curEnd)
                {
                    if (i == size)  lens.push_back(preLen+curLen);
                    else if (preLen+curLen < lens[i])
                    {
                        lens[i] = preLen+curLen;
                    }
                    else break;
                }
            }
        }
        return lens.size();
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> courses = {
        //{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}
        //{1,2}, {2,3}
        {2,3},{6,8},{6,11},{3,12},{3,13}, {3,14}
    };
    auto res = sol.scheduleCourse(courses);
    cout << res << endl;
    return 0;
}
