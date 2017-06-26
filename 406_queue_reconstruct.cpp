#include <iostream>
#include <vector>
#include <list>
#include <iterator>

// 1. Sort with height from Tall to Short
// 2. Append 2nd group using k val

using namespace std;

class Solution {
    public:
        vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
            using people_t = pair<int, int>;
            auto cmp = [](const people_t& l, const people_t& r){
                return l.first > r.first || 
                    ( l.first == r.first && l.second < r.second);
            };
            sort(people.begin(), people.end(), cmp);
            
            list<people_t> res;
            int size = people.size();
            for (int i=0; i<size; ++i){
                auto& p = people[i];
                auto it = res.begin();
                advance(it, p.second);
                res.insert(it, p);
                if (p.first != people[i-1].first){
                    cur = i;
                }
            }
            
            vector<people_t> r_vec = {res.begin(), res.end()};
            return r_vec;
        }
};

int main(){
    using people_t = pair<int, int>;
    vector<people_t> people = {
        {7,0},
        {4,4},
        {7,1},
        {5,0},
        {6,1},
        {5,2}
    };
    Solution sol;
    auto res = sol.reconstructQueue(people);
    for (auto& p:res){
        cout << p.first << ", " << p.second << endl;
    }
    return 0;
}
