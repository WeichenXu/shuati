#include <iostream>
using namespace std;

// 1. calculate overlapped area
// 2. two seperate space - 1st result

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // 1. calc overlapped area
        int left = max(A,E), right = min(C, G);
        int bottom = max(B,F), up = min(D,H);
        int overlapped = 0;
        if (right > left && up > bottom)
        {
            overlapped = (up-bottom)*(right-left);
        }
        return (C-A)*(D-B)+(G-E)*(H-F)-overlapped;
    }
};

int main(){
    Solution sol;
    auto res1 = sol.computeArea(-3,0,3,4,0,-1,9,2);
    auto res2 = sol.computeArea(0,-1,9,2,-3,0,3,4);
    cout << res1 << " " << res2 << endl;
    int i = 1500000001;
    auto res3 = sol.computeArea(-i-1, 0, -i, 1, i, 0, i+1, 1);
    cout << res3 << endl;
}
