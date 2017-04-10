#include <sstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cassert>

// 1. Tokenize the str
// 2. Keep a mapping between char & word

using namespace std;

class Solution{
public:
    bool wordPattern(string pattern, string str){
        unordered_map<char, int> patMap;
        unordered_map<string, int> strMap;
        istringstream f(str);
        int i = 0, len = pattern.length();
        cout << "Staring for pattern:" << pattern << ", str:" << str << endl;
        for (string token; f >> token; ++i){
            if (len <= i || patMap[pattern[i]] != strMap[token])    return false;
            patMap[pattern[i]] = strMap[token] = i+1;
        }
        return i == len;
    }
};

int main(){
    vector<pair<string, string>> true_cases = {
        {"aba", "testA testB testA"},
        {"abba", "testA testB testB testA"},
        {"a", "testA"}
    };
    vector<pair<string, string>> wrong_cases = {
        {"", "test"},
        {"aa", "test"},
        {"aa", "testA testB"},
        {"aba", "testA testB testC"}
    };
    Solution sol;
    for (auto& c:true_cases){
        assert( sol.wordPattern(c.first, c.second) == true );
    }
    for (auto& c:wrong_cases){
        assert( sol.wordPattern(c.first, c.second) == false);
    }
    return 0;
}
