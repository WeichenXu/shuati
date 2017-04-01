#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        res.resize(n);
        for (int i=1; i<=n; ++i){
            if (! (i%15)){
                res[i-1] = "FizzBuzz";
            }
            else if (! (i%3)){
                res[i-1] = "Fizz";
            }
            else if (! (i%5)){
                res[i-1] = "Buzz";
            }
            else{
                res[i-1] = to_string(i);
            }
        }
        return res;
    }
};

int main(){
    int n = 20;
    Solution sol;
    auto res = sol.fizzBuzz(n);
    for (auto& str:res){
        cout << str << endl;
    }
    cout << endl;
    return 0;
}
