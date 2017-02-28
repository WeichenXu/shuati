#include <iostream>
#include <vector>
#include <string>

// 1. use DFS to backtracking

using namespace std;

class Solution{
public:
    vector<string> removeInvalidParentheses(string s){
        helper(s, 0, 0, {'(', ')'});
        return res;
    }
private:
    vector<string> res;
    void helper(string s, int prefix_i, int last_remove_i, const vector<char>& par){
        // validate the next prefix
        for (int i=prefix_i, count=0; i < s.length(); ++i){
            if (s[i] == par[0]) ++count;
            if (s[i] == par[1]) --count;
            if (count >= 0)  continue;
            // remove an possible pair
            for (int j=last_remove_i; j<=i; ++j){
                if (s[j] == par[1] && (j == last_remove_i || s[j-1] != par[1]))
                    helper(s.substr(0, j)+s.substr(j+1), i, j, par);
            }
            return;
        }
        // check the reverse pairs 
        reverse(s.begin(), s.end());
        if (par[0] == '('){
            helper(s, 0, 0, {')', '('});
        }
        else{
            res.push_back(s);
        }
    }
};

int main(){
    string s = "()())()";
    Solution sol;
    auto res = sol.removeInvalidParentheses(s);
    for (const auto&str:res){
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
