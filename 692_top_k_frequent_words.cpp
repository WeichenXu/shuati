#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        using map_t = unordered_map<string, int>;
        using iter = map_t::iterator; 
        map_t m;
        auto cmp = [](auto l, auto r){ return l->second > r->second || (l->second == r->second && l->first < r->first);};
        priority_queue<iter, vector<iter>, decltype(cmp)> q(cmp);
        for (const auto& word:words)
        {
            ++m[word];
        }
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            cout << "push " << it->first << ", " << it->second << endl;
            q.push(it);
            if (q.size() > k)
            {
                cout << "pop " << q.top()->first << endl;
                q.pop();
            }
        }
        vector<string> res;
        while (not q.empty())
        {
            res.push_back(q.top()->first);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    vector<string> ss = {
        "i", "love","i","love","u", "love"
    };
    Solution sol;
    auto res = sol.topKFrequent(ss, 2);
    for (const auto& str:res)
    {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
