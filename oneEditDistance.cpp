#include <iostream>
#include <string>

// determine the sub sequence differ by one

using namespace std;

class Solution{
public:
    bool isOneEditDistance(string s, string t){
        // go to the place where two string differ
        int sLen = s.length(), tLen = t.length();
        int i=0;
        for (; i<min(sLen, tLen); ++i){
            if (s[i] != t[i]){
                break;
            }
        }
        if (sLen > tLen){
            return s.substr(i+1) == t.substr(i);
        }
        else if (sLen < tLen){
            return s.substr(i) == t.substr(i+1);
        }
        else {
            return (i != s.length()) && s.substr(i+1) == t.substr(i+1);
        }
        return false;
    }
};

int main(){
    string s = "acb", t = "aab";
    Solution sol;
    auto res = sol.isOneEditDistance(s, t);
    cout << s << " and " << t << ", is one edit distance " << res << endl;
    return 0;
}
