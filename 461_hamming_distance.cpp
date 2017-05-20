#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        x ^= y;
        int res = 0;
        while (x){
            x &= (x-1);
            ++res;
        }
        return res;
    }
};

int main(){
    Solution sol;
    assert (sol.hammingDistance(0,4) == 1);
    assert (sol.hammingDistance(1,4) == 2);
    return 0;
}
