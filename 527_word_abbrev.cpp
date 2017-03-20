#include <iostream>
#include <string>

#include <vector>
#include <map>
#include <unordered_set>

// 1. split the strings in different buckets by length
// 2. each bucket, check if there are dups, update until empty dups

using namespace std;

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        vector<string> res;
        int size = dict.size();
        res.resize(size);
        map<int, vector<pair<string, int>>> buckets;
        for (int i=0; i<size; ++i){
            string& str = dict[i];
            buckets[str.length()].push_back({str, i});
        }
        for (auto it=buckets.begin(); it != buckets.end(); ++it){
            helper(it->first, it->second, res);
        }
        return res;
    }

private:
    string generateAbbr(const string& str, int prefix){
        int len = str.length();
        if (prefix >= len-2){
            return str;
        }
        string res = str.substr(0, prefix);
        int aft = len - prefix;
        res += to_string(aft-1);
        res += str.back();
        return res;
    }
    void helper(int len, vector<pair<string, int>>& strs, vector<string>& res){
        int size = strs.size();
        vector<int> abbr(strs.size(), 1);
        vector<string> cur;
        cur.resize(size);
        for (int i=0; i<size; ++i){
            cur[i] = generateAbbr(strs[i].first, 1); 
            abbr[i] = 1;
        }
        
        if (len >= 4){
            for (int i=0; i<size; ++i){
                while(1){
                    unordered_set<int> dups;
                    for(int j=i+1; j<size; ++j){
                        if (cur[j] == cur[i])   dups.insert(j);
                    }
                    if (dups.empty())   break;
                    dups.insert(i);
                    // extend the prefix
                    for(auto idx:dups){
                        cur[idx] = generateAbbr(strs[idx].first, ++abbr[idx]);
                    }
                }
            }
        }

        for (int i=0; i<size; ++i){
            res[strs[i].second] = cur[i];
        }
    }
};

int main(){
    vector<string> str = {
        "like", 
        "god", 
        "internal", 
        "me", 
        "internet", 
        "interval", 
        "intension", 
        "face", 
        "intrusion"
    };
    Solution sol;
    auto res = sol.wordsAbbreviation(str);
    for (auto& str:res){
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
