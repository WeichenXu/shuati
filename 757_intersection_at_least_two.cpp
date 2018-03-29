#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& l, const auto& r){return l[0] < r[0];});
        int first = INT_MAX, second = INT_MAX, num = 0;
        for (auto it = intervals.rbegin(); it != intervals.rend(); ++it)
        {
            int left = (*it)[0], right = (*it)[1];
            if (right >= second) continue;
            else if (right >= first)
            {
                second = first == left?left+1:first;
                first = left;
                ++num;
            }
            else
            {
                first = left;
                second = left+1;
                num += 2;
            }
        }
        return num;
    }
};

int main()
{
    vector<vector<int>> intervals={
        {1,3},
        {1,4},
        {2,5},
        {3,5}
    };
    Solution sol;
    auto res = sol.intersectionSizeTwo(intervals);
    cout << res << endl;
    return 0;
}
