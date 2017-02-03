#include <iostream>
#include <string>

// push the non'-' char into the res and append '-' every K chars
// reverse result when finished
//
// edge cases: 
// 1. when '-' at begining
// 2. the encoded string is empty

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int len = S.length();
        string res;
        int count = 0;
        for (int i=len-1; i>=0; --i){
            char cur = S[i];
            if (cur != '-'){
                ++count;
                if (cur >= 'a' && cur <= 'z'){
                    cur += 'A' - 'a';
                }
                res+=cur;
                if (count == K){
                    res += '-';
                    count = 0;
                }
            }
        }
        
        if(!res.empty() && res.back() == '-'){
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

int main(){
    Solution sol;
    string str = "-abc-cde";
    int k = 15;
    cout << sol.licenseKeyFormatting(str, 1);
    return 0;
}
