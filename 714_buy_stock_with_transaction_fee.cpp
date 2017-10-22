#include <iostream>

// two states, s0: no stock; s1: hold stock
// update s0, by selling previous s1
// update s1, by buyring previous s0

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int s0 = 0;
        int s1 = INT_MIN;
        for (const auto px:prices)
        {
            int tmp = s0;
            s0 = max(s0, s1+px);
            s1 = max(s1, tmp-px-fee);
        }
        return s0;
    }
};
