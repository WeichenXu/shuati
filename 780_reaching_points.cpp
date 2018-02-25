#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // b/c sx > 0 and sy > 0
        // we could larger%smaller until refind (sx,sy)
        while (tx >= sx && ty >= sy)
        {
            if (tx < ty)
            {
                ty %= tx; 
            }
            else
            {
                tx %= ty;
            }
        }
        if (tx > ty)
        {
            return tx == sx && ty == sy%sx;
        }
        return ty == sy && tx == sx%sy;
    }
};

int main()
{
    Solution sol;
    assert(true == sol.reachingPoints(1,2,5,2));
    assert(false == sol.reachingPoints(4, 10, 10, 14));
    assert(false == sol.reachingPoints(4, 10, 11, 10));
    assert(true == sol.reachingPoints(1,1,3,5));
    assert(false == sol.reachingPoints(10,4,10,20));
    assert(true == sol.reachingPoints(1,5,999999996,5));
    return 0;
}
