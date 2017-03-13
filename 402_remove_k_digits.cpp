#include <iostream>
#include <string>
#include <stack>

#include <cassert>

// 1. using Greedy way
//    remove the largest digit in subarray, which is monolithic (increasing)
//    for k steps

// 2. using Stack
//    push the element if >=
//    pop if larger than current element for k times
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        // push the elements into the stack
        for (int i=0; i<num.size(); ++i){
            while(!s.empty() && s.top()>num[i] && k){
                s.pop();
                --k;
            } 
            s.push(num[i]);
        }
        // remove remaining elements
        while(k){
            s.pop();
            --k;
        }
        string res;
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        // remove leading zeros
        int i=0;
        while(i < res.length() && res[i] == '0'){
            ++i;
        }
        res.erase(0, i);
        return res.empty() ? "0":res;
    }
};

int main(){
    string num1 = "1432219";
    string num2 = "10029";
    string num3 = "123";

    int k11 = 2;
    int k12 = 7;
    int k21 = 1;
    int k22 = 2;

    Solution sol;
    assert(sol.removeKdigits(num1, k11) == "12219");
    assert(sol.removeKdigits(num1, k12) == "0");
    assert(sol.removeKdigits(num2, k21) == "29");
    assert(sol.removeKdigits(num2, k22) == "2");
    assert(sol.removeKdigits(num3, 1) == "12");

    return 0;
}
