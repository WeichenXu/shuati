#include <iostream>
#include <string>
#include <list>

#include <vector>

// 1. Start with a single number '1'
// 2. Extend the string one by one
using namespace std;

class Solution {
public:
    vector<int> findPermutation(string s) {
        list<int> res;
        //if (s.empty())  return {1};
        res.push_back(1);
        auto it = res.begin();
        for (int i=0; i<s.length(); ++i){
            if (s[i] == 'I'){
                res.push_back(i+2);
                it = prev(res.end());
            }
            else {
                it = res.insert(it, i+2);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};

int main(){
    string s = "III";
    Solution sol;
    auto res = sol.findPermutation(s);
    for (auto n:res){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
