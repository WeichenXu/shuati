#include <iostream>

// Binary Search

using namespace std;

static constexpr int target = 1702766719;

int guess(int n){
    cout << "\t trying " << n << endl;
    if (n == target)    return 0;
    return target > n ? 1:-1;
}

class Solution{
public:
    int guessNumber(int n){
        long lo=1, hi=n;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            int res = guess(mid);
            if (!res){
                return mid;
            }
            if (res > 0){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return lo;
    }
};

int main(){
    Solution sol;
    auto t = sol.guessNumber(2126753390);
    cout << t << endl;
    return 0;
}
