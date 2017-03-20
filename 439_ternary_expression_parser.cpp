#include <iostream>
#include <string>
#include <cassert>

#include <vector>
#include <stack>

// 1. Use stack
// 2. group right to left

using namespace std;

class Solution {
public:
    string parseTernary(string expression) {
        int len = expression.length();
        stack<char> s;
        // scan from right to left
        for (int i=len-1; i>=0; --i){
            char cur = expression[i];
            if (cur == '?' || cur == ':')   continue;
            if (i == len-1 || expression[i+1] != '?') {
                s.push(cur);
            }
            else{
                char l = s.top();
                s.pop();
                char r = s.top();
                s.pop();
                char toChoose = ( (cur == 'T') ? l : r );
                s.push(toChoose);
            }
        }
        return string(1, s.top());
    }
};

int main(){
    vector<string> exps = {
        "T?2:3",
        "T?F?2:3:2",
        "T?T:F?T:F"
    };
    vector<string> res = {
        "2",
        "3",
        "T"
    };
    Solution sol;
    for (int i=0; i<exps.size(); ++i){
        auto r = sol.parseTernary(exps[i]);
        cout << "Exp: " << exps[i] << ", Res: " << r << endl;
        assert(r == res[i]);
    }
    return 0;
}
