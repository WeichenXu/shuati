#include <iostream>
#include <string>

#include <cassert>

// using Greedy way
// remove the largest digit in subarray, which is monolithic (increasing), for k steps

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        for (int i=0; i<k; ++i){
            if (num.size() < 2)    return "0";
            // locate the increasing subarray
            int j = 1;
            while(j < num.length() && num[j] >= num[j-1]){
                ++j;
            }
            // erase the largest element
            num.erase(j-1, 1);
            // remove leading 0s
            j=0;
            while(j < num.length() && num[j] == '0'){   
                ++j; 
            }
            num.erase(0, j);
        }
        if (num.empty()) num = "0";
        return num;
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
