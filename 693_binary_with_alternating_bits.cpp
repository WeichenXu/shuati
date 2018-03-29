#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        while (n)
        {
            if (not (n & 0b1)^((n>>1) & 0b1))
            {
                return false;
            }
            n = (n>>1);
        }
        return true;
    }
};

int main()
{
    Solution sol;
    assert(sol.hasAlternatingBits(5) == true);
    assert(sol.hasAlternatingBits(0) == true);
    assert(sol.hasAlternatingBits(1) == true);
    assert(sol.hasAlternatingBits(8) == false);
    assert(sol.hasAlternatingBits(4) == false);
}
