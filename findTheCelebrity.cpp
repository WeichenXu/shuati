#include <iostream>
#include <vector>

// 1. locate the only possible celebrity 
// 2. whether it is valid

using namespace std;

//bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int cel = 0;
        if (n <= cel)   return -1;
        for (int i=0; i<n; ++i){
            if (!knows(i, cel)){
                cel = i;
            }
        }
        for (int i=0; i<n; ++i){
            if (i == cel)   continue;
            if (knows(cel, i) || !knows(i, cel))    return -1;
        }
        return cel;
    }
};

int main(){
    int n = 10;
    Solution sol;
    auto res = sol.findCelebrity(n);
    cout << "Celebrity is " << res << endl;
    return 0;
}
