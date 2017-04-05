#include <iostream>
#include <locale>
#include <cctype>
#include <cassert>
#include <string>
#include <algorithm>

#include <vector>
#include <unordered_map>
// Quesiton: how many letters need to be modified
// 1. 6 <= len <= 20
// 2. must contain Upper/Lower/Digit
// 3. no more same continuous letters longer than 3
//  Divide the general problem into two
//      a. len <= 20
//         Optimal answer would be max(replace+add_len, add_char)
//      b. len > 20
//         Optimal answer would be toDelete + max(to_replace, add_char)

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string s) {
        locale loc;
        int upperLetter = 1, lowerLetter = 1, digitLetter = 1;
        int addTarget = max(0, 6-(int)s.length()), deleteTarget = max(0, (int)s.length() - 20);
        int toAdd = 0, toReplace = 0, toDelete = 0;

        // Greedy for length <= 20
        for (int l=0, r=0; r < s.length(); ++r){
            // Requirement II
            if (islower(s[r], loc))  lowerLetter = 0;
            if (isupper(s[r], loc))  upperLetter = 0;
            if (isdigit(s[r], loc))  digitLetter = 0;
            // Add or Replace a letter for duplicate chars
            if (r-l == 2){
                if (s[r] == s[r-1] && s[r-1] == s[r-2]){
                    if (toAdd < addTarget){
                        ++ toAdd;
                        l = r;
                    }
                    else{
                        ++ toReplace;
                        l = r+1;
                    }
                }
                else{
                    ++l;
                }
            }
        }

        if (s.length() <= 20){
            return max(toReplace + addTarget, upperLetter + lowerLetter + digitLetter);
        }
        
        vector<unordered_map<int,int>> lenSub(3);
        // Store the mapping of len%3 to len
        for(int l=0, r=0; r <= s.length(); ++r){
            if (r == s.length() || s[r] != s[l]){
                int len = r-l;
                if (len>2){
                    ++lenSub[len%3][len];
                }
                l = r;
            }
        }
        
        // Dimish Replacement as many as possible
        toReplace = 0;
        for(int i=0, numLetter, dec; i<3; ++i){
            for(auto it = lenSub[i].begin(); it != lenSub[i].end(); ++it){
                if (i < 2){
                    numLetter = i+1, dec = min(it->second, (deleteTarget-toDelete)/numLetter);
                    toDelete += dec * numLetter;
                    it->second -= dec;
                    if (it->first - numLetter > 2) {
                        lenSub[2][it->first-numLetter] += dec;
                    }
                }
                toReplace += (it->first / 3)*(it->second);
            }
        }

        int dec = (deleteTarget - toDelete)/3;
        toReplace -= dec, toDelete += 3*dec;
        return deleteTarget + max(toReplace, upperLetter+lowerLetter+digitLetter);
    }
};

int main(){
    Solution sol;
    vector<pair<string, int>> cases = {
        {"ABCab1", 0},
        {"aaaaaa", 2},
        {"aaaa", 2},
        {"ABABABABABABABABABAB1", 2}
    };
    for (auto&it:cases){
        auto res = sol.strongPasswordChecker(it.first);
        cout << "\t Original str:" << it.first << endl;
        cout << "\t Optimal ans:" << res << endl;
        assert( res == it.second );
    }
    return 0;
}
