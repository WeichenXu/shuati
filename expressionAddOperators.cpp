#include <iostream>
#include <string>
#include <vector>

// Divide and conquer
// 1. overflow: INT_MAX * INT_MAX
// 2. sequence started with 0
// 3. store the last value before '*' to record the state

using namespace std;

class Solution{
public:
    vector<string> addOperators(string num, int target){
        helper(num, target, 0, 0, "", 0);
        return res;
    }
private:
    void helper(string& num, int target, int idx, long now, string cur, long last){
        if (idx == num.length() && now == target){
            res.push_back(cur);
            return;
        }
        // add an op after idx
        for (int i=idx; i < num.length(); ++i){
            if (i != idx && num[idx] == '0') break;
            string nx = num.substr(idx, i-idx+1);
            long val = stol(nx);
            if (!idx){
                helper(num, target, i+1, val, nx, val);
            }
            else{
                helper(num, target, i+1, now+val, cur+"+"+nx, val);
                helper(num, target, i+1, now-val, cur+"-"+nx, -val);
                helper(num, target, i+1, now-last+val*last, cur+"*"+nx, val*last);
            }
        }
    }

    vector<string> res;
};

int main(){
    Solution sol;
    string num = "001203";
    int target = 6;
    auto res = sol.addOperators(num, target);
    for (auto& str:res){
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
