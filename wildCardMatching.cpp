#include <iostream>
#include <vector>
#include <cassert>

// Solution 1:
// use dp solution
// matched[i][j] = p[i] match s[j]
//          s
//     a  a  a  b
// p ?
//   a
//   a
// Three cases, switch by p[i]
// 1. if p[i] is not a '*'
//       matched[i][j] == matched[i-1][j-1] && p[i] == '?' || p[i] == s[j]
// 2. else
//       matched[i][j] == matched[i-1][j] || matched[i][j-1]
// Edge case, when i == 0

// Optimization
//   Since we only need to update the last row elements, we could use only one row to store

// Solution 2:
// Two pointers:
// 1. s[i] == p[j] || p[j] == '?'
//    ++i, ++j
// 2. if p[j] == '*'
// 2. else, consider about '*'

using namespace std;

class Solution{
public:
    bool isMatch(string s, string p){
        // initialize the dp matrix
        int sLen = s.length(), pLen = p.length();
        vector<int> dp(sLen+1, 0);
        dp[0] = 1;

        // update the dp matrix row by row
        for (int i=1; i<=pLen; ++i){
            if (p[i-1] == '*'){
                for (int j=1; j<=sLen; ++j){
                    dp[j] = (dp[j] || dp[j-1]);
                }
            }
            else{
                for (int j=sLen; j>=1; --j){
                    dp[j] = (dp[j-1] && (p[i-1] == '?' || p[i-1] == s[j-1]));
                }
            }
            dp[0] = (p[i-1] == '*' && dp[0]);
            for (auto i:dp){
                cout << i << " ";
            }
            cout << endl;
        }

        return dp[sLen];
    }

    bool isMatchII(string s, string p){
        int i=0, j=0;
        int start = -1, lastMatch = -1;
        int lenS = s.length(), lenP = p.length();
        while(i < lenS){
            // if s[i] == p[j] || p[j] == '?'
            if (j<lenP && (s[i] == p[j] || p[j] == '?')){
                ++i, ++j;
            }
            else if (j<lenP && p[j] == '*'){
                start = j++;
                lastMatch = i;
            }
            else if (start >= 0){
                j = start+1;
                i = ++lastMatch;
            }
            else{
                return false;
            }
        }
        // remove all the remaining '*' in p
        while(j < lenP && p[j] == '*'){
            ++j;
        }
        return i == lenS && j == lenP;
    }
};

int main(){
    Solution sol;
    string str1 = "aab", str2 = "", str3 = "zacabz";
    string pat1 = "*", pat2="*ba", pat3="*b", pat4="aab", pat5="*a?b*";
    // test for str1
    assert(sol.isMatchII(str1, pat1) == true);
    assert(sol.isMatchII(str1, pat2) == false);
    assert(sol.isMatchII(str1, pat3) == true);
    assert(sol.isMatchII(str1, pat4) == true);
    
    // test for str2
    assert(sol.isMatchII(str2, pat1) == true);
    assert(sol.isMatchII(str2, pat3) == false);

    // test for str3
    assert(sol.isMatchII(str3, pat5) == false);
    return 0;
}


