#include <iostream>

#include <vector>
#include <set>

#include <algorithm>
// 1. Use a tree-based set to store all intervals
// 2. Update current node
//      a. Find the current node <= val
//      b. delete and update it

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        intervals.clear();
    }

    void addNum(int val) {
        auto it = intervals.lower_bound(Interval(val, val));
        if (it!=intervals.begin() && prev(it)->end + 1 >= val){
            --it;
        }
        int start = val, end = val;
        
        // remove all intervals should contain val
        while (it != intervals.end() && it->start - 1 <= val && it->end + 1 >= val){
            start = min(it->start, start);
            end = max(it->end, end);
            it = intervals.erase(it);
        }
        
        // insert updated interval
        intervals.insert(it, Interval(start, end));
    }

    vector<Interval> getIntervals() {
        return vector<Interval>(intervals.begin(), intervals.end());
    }
private:
    struct cmp{
        bool operator()(const Interval& l, const Interval& r)const {
            return l.start < r.start;
        }
    };
    set<Interval, cmp> intervals;
};

/**
 *  * Your SummaryRanges object will be instantiated and called as such:
 *      */
void print_intervals(vector<Interval>& intervals){
    for (const auto&interval : intervals){
        cout << "\t Range: " << interval.start << ", " << interval.end << endl;
    }
    cout << endl;
}


int main(){
    SummaryRanges obj;
    vector<int> nums = {1,9,2,1, 2,4,3,5,10};
    for (auto num:nums){
        obj.addNum(num);
        auto res = obj.getIntervals();
        print_intervals(res);
    }
    return 0;
}
