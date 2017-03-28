#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

/* Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        using node_t = pair<int, int>;
        vector<node_t> nodes;
        for (const auto&i : intervals){
            nodes.push_back({i.start, 1});
            nodes.push_back({i.end, -1});
        }

        auto cmp = [](const node_t& left, const node_t& right){
            return left.first < right.first || 
                (left.first == right.first && left.second < right.second);
        };
        sort(nodes.begin(), nodes.end(), cmp);
        
        // iterate all the nodes
        int res = 0, cur = 0;
        for (const auto&n:nodes){
            cur += n.second;
            res = max(cur, res);
        }

        return res;
    }
};

int main(){
    vector<Interval> intervals = {
        {1, 3},
        {2, 4},
        {3, 5}
    };

    Solution sol;
    auto res = sol.minMeetingRooms(intervals);
    cout << "Minimum meeting rooms: " << res << endl;
    return 0;
}
