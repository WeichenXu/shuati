#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

// keep project with same cost in same bucket (ascending by profit)
// each time maintain a priority queue with iterator of candidate bucket
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        //init buckets 
        using bucket = multiset<int, greater<int>>;
        map<int, bucket> buckets;
        int size = Profits.size();
        for (int i=0; i<size; ++i)
        {
            buckets[Capital[i]].insert(Profits[i]);
        }
        // init priority_queue
        using node = pair<int, int>;
        auto cmp = [](const auto& l, const auto& r){
            return l.second < r.second;
        };
        priority_queue<node, std::vector<node>, decltype(cmp)> q(cmp);
        for (auto it:buckets)
        {
            if (it.first > W)
            {
                break;
            }
            q.push({it.first, *(it.second.begin())});
        }
        // iterate until res find
        while (k && not q.empty())
        {
            --k;
            auto it = q.top();
            q.pop();
            int curProfit = it.second;
            // update candidates
            auto& bucket = buckets[it.first];
            auto itErase = bucket.find(it.second);
            bucket.erase(itErase);
            if (not bucket.empty())
            {
                q.push({it.first, *(bucket.begin())});
            }
            auto l = buckets.upper_bound(W);
            W += curProfit;
            while (l != buckets.end() && l->first <= W)
            {
                q.push({l->first, *(l->second.begin())});
                ++l;
            }
        }
        return W;
    }
};

int main()
{
    Solution sol;
    int k = 10;
    int W = 0;
    vector<int> Profits= {1,2,3};
    vector<int> Capital = {0,1,2};
    cout << sol.findMaximizedCapital(k, W, Profits, Capital) << endl;
    return 0;
}
