#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        map<int, unordered_set<char>> dict;
        // 1. get a sorted mapping {cnt -> char array}
        for (const auto ch:s)
        {
            auto it = cnt.find(ch);
            if (it == cnt.end())
            {
                it = cnt.insert({ch, 0}).first;
                dict[0].insert(ch);
            }
            auto prev = it->second;
            cnt[ch] = prev+1;
            dict[prev].erase(ch);
            dict[prev+1].insert(ch);
        }
        string res = "";
        // 2. concatenate as a string, then reverse
        for (auto& it:dict)
        {
            auto& chars = it.second;
            cout << "Times: " << it.first << endl;
            for (const auto ch:chars){
                cout << ch << " ";
                res += string(it.first, ch);
            }
            cout << endl;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution sol;
    auto str = sol.frequencySort("erteaabbbc");
    cout << str << endl;
    return 0;
}
