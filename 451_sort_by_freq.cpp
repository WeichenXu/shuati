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
        // 1.1 count occurance of each char
        // 1.2 sort with occurance
        for (const auto ch:s)
        {
            cnt[ch]++;
        }
        for (auto& itr:cnt)
        {
            dict[itr.second].insert(itr.first); 
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
