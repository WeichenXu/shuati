#include <iostream>
#include <string>
#include <vector>

// 1. generate all abbreviations for target string
// 2. sort the abbrs from small to large with the string's length
// 3. find the first abbr, which invalid all word in the dictionary

using namespace std;

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        
        auto abbrs = generateAbbrev(target);
        sort(abbrs.begin(), abbrs.end(), [](const string& l, const string& r){ return l.length() < r.length(); });
        for (const auto& abbr:abbrs){
            bool allInvalid = true;
            for (const auto& word:dictionary){
                if (validAbbreviation(word, abbr)){
                    allInvalid = false;
                    break;
                }
            }
            if (allInvalid){
                return abbr;
            }
        }
        return "";
    }

private:

    // utility function: whether abbrev is valid for string str
    bool validAbbreviation(const string &word, const string& abbr){
        int i = 0, j = 0;

        while (i < word.length() && j < abbr.length()){
            int num = 0;
            while (j < abbr.length() && abbr[j]>='0' && abbr[j]<='9' ){
                if (!num && abbr[j] == '0'){
                    return false;
                }
                num = num*10 + abbr[j]-'0';
                ++j;
            }
            i += num;
            if (i >= word.length() || j >= abbr.length() || word[i] != abbr[j]){
                break;
            }
            ++i, ++j;
        }

        return i == word.length() && j == abbr.length();
    }

    // utility function: generate all possible abbrevs
    vector<string> generateAbbrev(string& str){
        int len = str.length();
        int size = 1 << len;
        vector<string> res;
        for(int i=0; i<size; ++i){
            // convert to bit set
            bitset<20> cur(i);
            int zeros = 0;
            string abbr = "";
            for (int j=0; j<len; ++j){
                if (!cur[j]){
                    ++zeros;
                }
                if (cur[j] || j==len-1){
                    if (zeros){
                        abbr += to_string(zeros);
                        zeros = 0;
                    }
                    if (cur[j]){
                        abbr += str[j];
                    }
                }
            }   
            res.push_back(abbr);
        }
        return res;
    }
};

int main(){
    Solution sol;
    string target = "apple";
    vector<string> dic = {"plain", "amber", "blade"};
    auto str = sol.minAbbreviation(target, dic);
    cout << str << endl; 
    return 0;
}
