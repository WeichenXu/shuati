#include <iostream>
#include <algorithm>
/*
0 | 1 | 2 | ........        Level cur,
|   \
|     \
|       \
0,1,2...9|0,1,2,3 ....      Level cur+1
*/

// 2. Denery tree
//    a.  Main function: 
//          If steps remaing is larger, go to next in Level cur
//          Else go to Level cur+1
//    b.  Calculate steps:
//          Return the steps between two node in Same Level
using namespace std;

class Solution {
private:
    // return the steps between n1&n2 in range[1,n] based on Denery tree
    int calSteps(int n, long n1, long n2){
        long steps = 0;
        while (n1  <= n){
            steps += min((long)n+1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }

public:
    int findKthNumber(int n, int k) {
        if (k > n || k <= 0) return 0;
        long cur = 1;
        --k;
        while(k > 0){
            int steps = calSteps(n, cur, cur+1);
            if (steps <= k){
                k -= steps;
                ++cur;
            }
            else{
                cur *= 10;
                --k;
            }
        }
        return cur;
    }
};

int main(){
    int n = 10, k=3;
    Solution sol;
    auto res = sol.findKthNumber(n, k);
    cout << "Res: " << res << endl;
    return 0;
}
