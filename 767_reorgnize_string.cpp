#include <iostream>
#include <string> 
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using mm = unordered_map<char, int>;
    string reorganizeString(string S) {
        mm m;
        const int size = S.length();
        for (auto ch:S) 
        {
            int cnt = ++m[ch];
            if (cnt >= (size+1)/2)   return "";
        }
        auto cmp = [&](auto l, auto r){
            return l->second < r->second;
        };
        priority_queue<mm::iterator, vector<mm::iterator>, decltype(cmp)> pq(cmp);
        for (auto it = m.begin(); it != m.end(); ++it) pq.push(it);
        string res = "";
        while (not pq.empty())
        {
            auto first = pq.top();
            pq.pop();
            if (res.empty() || res.back() != first->first)
            {
                res += first->first;
                --first->second;
            }
            else
            {
                auto second = pq.top();
                pq.pop();
                res += second->first;
                if(--second->second != 0) pq.push(second);
            }
            if (first->second)  pq.push(first);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string S = "aab";
    auto res = sol.reorganizeString(S);
    cout << res << endl;
}
