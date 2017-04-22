#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cassert>

// 1. Backtracking: Recursively consume pattern
using namespace std; 

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        pat2str.clear(), str2pat.clear();
        return backtrack(pattern, str, 0, 0);
    }
private:
    unordered_map<char, string> pat2str;
    unordered_map<string, char> str2pat;

    bool backtrack(string &pattern, string &str, int curPat, int idxOfStr){
        cout << "\tpatIdx:" << curPat << ", strIdx:" << idxOfStr << endl;
        // idx is beyond the end of the string
        if (idxOfStr >= str.length()){
            return curPat >= pattern.length();
        }
        if (curPat >= pattern.length()){
            return idxOfStr >= str.length();
        }

        // if we have pre-matched pattern
        char curP = pattern[curPat];
        if (pat2str.find(curP) != pat2str.end()){
            string patstr = pat2str[curP];
            cout << "\t pre pat:" << curP << ", str:" << patstr << endl;
            if (patstr.length() > (str.length()-idxOfStr+1) 
              || str.substr(idxOfStr, patstr.length()) != patstr){
                return false;
            }
            return backtrack(pattern, str, curPat+1, idxOfStr + patstr.length());
        }
        // else try all possible mapping
        else{
            for (int i=idxOfStr; i < str.length(); ++i){
                string patstr = str.substr(idxOfStr, i-idxOfStr+1);
                if(str2pat.find(patstr) == str2pat.end()){ 
                    pat2str[curP] = patstr;
                    str2pat[patstr] = curP;
                    if (backtrack(pattern, str, curPat+1, i+1)){
                        return true;
                    }
                    pat2str.erase(curP);
                    str2pat.erase(patstr);
                }
            }
        }
        return false;
    }
};

int main(){
    vector<pair<string, string>> right_cases = {
        {"a", "a"},
        {"aba", "helloworldhello"},
        {"aaa", "ababab"}
    };
    vector<pair<string, string>> wrong_cases = {
        {"a", ""},
        {"", "a"},
        {"aa", "a"},
        {"abab", "xyzabcxzyabc"}
    };
    Solution sol;
    for (auto&it:right_cases){
        cout << "Pat: " << it.first << ", Str: " << it.second << endl;
        assert( sol.wordPatternMatch(it.first, it.second) == true);
    }
    for (auto&it:wrong_cases){
        cout << "Pat: " << it.first << ", Str: " << it.second << endl;
        assert( sol.wordPatternMatch(it.first, it.second) == false);
    }
    return 0;
}
