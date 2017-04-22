#include <iostream>

// 1. Iterate all k numbers in the range of n
//    a. append '0' as much as possible
//    b. ++ num if smaller than n
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        if (k <= 0 || k > n){
            return 0;
        }
        int i = 1, cur = 1;
        while (i < k){
            int nx;
            if (cur*10 <= n){
                nx = cur * 10;
            }
            else if (cur+1 <= n){
                nx = cur+1;
                while (! (nx % 10)){
                    nx /= 10;
                }
            }
            else {
                nx = cur/10 + 1;
            }
            cur = nx;
            ++i;
        }
        return cur;
    }
};

int main(){
    int n = 719885387, k=209989719;
    Solution sol;
    auto res = sol.findKthNumber(n, k);
    cout << "Res: " << res << endl;
    return 0;
}
