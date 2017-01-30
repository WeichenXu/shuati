#include <iostream>
#include <string>
#include <math.h>

// If a number n can be represented by 11111 in k base of m len
// 1. k^(m+1) = k*n - n + 1, (k^(m+1)-1)/(k-1) == n
// 2. since k^(m+1) > n > k^(m), k = n*(1/m) 

using namespace std;

class Solution{
public:
    string smallestGoodBase(string n){
        unsigned long num = stol(n);
        cout << "Find base for num: " << num << endl;
        // iterate all possible len
        unsigned long max_m = log(num)/log(2);
        for (unsigned long m=max_m; m>1; --m){
            unsigned long k = pow(num, 1.0/(float)m);
            cout << "m: " << m << ", k:" << k << endl;
            unsigned long val = 1;
            for(int i=0; i<m+1; ++i){
                val *= k;
            }
            cout << val-1 << endl
                 << (k-1) * num << endl;
            if (val-1 == (k-1) * num){
                return to_string(k);
            }
        }

        return to_string(num-1);
    }
};

int main(){
    Solution sol;
    string num="13";
    string num2="4681";
    string num3="14919921443713777";
    string num4="470988884881403701";
    cout << sol.smallestGoodBase(num4) << endl;
}
