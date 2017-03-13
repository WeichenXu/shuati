#include <iostream>
#include <string>

#include <cassert>

// using Greedy way
// remove the largest digit in subarray, which is monolithic (increasing), for k steps

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        // remove the "peak" element
        while(k){
            int size = num.size(), i = 0;
            while (i+1 < size && num[i] <= num[i+1]){
                ++i;
            }
            num.erase(i, 1);
            --k;
        }
        // remove the leading zeros
        int i = 0, n = num.size();
        while (i < n && num[i] == '0'){
            ++i;
        }
        num.erase(0, i);
        return num.empty() ? "0":num;
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
