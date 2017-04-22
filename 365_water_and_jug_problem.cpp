#include <iostream>
#include <cassert>

// Bezout's identity
// ax+by = n*gcd(x, y)
// 2*5-2*3 = 6, Fill 5 twice, and pull 3 twice
// Similar problem: https://www.hackerrank.com/challenges/possible-path

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z<0 || z > x+y) return false;
        return !z || z==x || z==y || z%gcd(x,y) == 0;
    }
private:
    int gcd(int a, int b){
        while(b){
            int tmp = b;
            b = a%b;
            a = tmp;
        }
        return a;
    }
};

int main(){
    Solution sol;
    assert (sol.canMeasureWater(5,2,4) == true);
    assert (sol.canMeasureWater(6,4,1) == false);
    return 0;
}
