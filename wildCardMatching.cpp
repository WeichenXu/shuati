#include <iostream>
#include <vector>
#include <cassert>

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

using namespace std;

class Solution{
public:
    bool isMatch(string s, string p){
        // initialize the dp matrix
        int sLen = s.length(), pLen = p.length();
        using vec_t = vector<int>;
        vector<vec_t> dp(pLen+1, vec_t(sLen+1, 0));
        dp[0][0] = 1;

        // update the dp matrix row by row
        for (int i=1; i<=pLen; ++i){
            if (p[i-1] == '*' && dp[i-1][0]){
                dp[i][0] = 1;
            }
            for (int j=1; j<=sLen; ++j){
                if (p[i-1] != '*'){
                    dp[i][j] = p[i-1] == '?' || p[i-1] == s[j-1];
                }
                else {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }

        return dp[pLen][sLen];
    }
};

int main(){
    Solution sol;
    string str1 = "aab", str2 = "";
    string pat1 = "*", pat2="*ba", pat3="*b", pat4="aab";
    // test for str1
    assert(sol.isMatch(str1, pat1) == true);
    assert(sol.isMatch(str1, pat2) == false);
    assert(sol.isMatch(str1, pat3) == true);
    assert(sol.isMatch(str1, pat4) == true);
    
    // test for str2
    assert(sol.isMatch(str2, pat1) == true);
    assert(sol.isMatch(str2, pat3) == false);
    return 0;
}


