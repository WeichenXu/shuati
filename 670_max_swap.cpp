#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        auto numStr = to_string(num);
        int size = numStr.length(), maxIdx = -1;
        vector<int> v(size, -1);
        for (int i=size-1; i>=0; --i)
        {
            if (maxIdx >= 0 and numStr[maxIdx] > numStr[i])
            {
                v[i] = maxIdx;
            }
            if (numStr[i] > numStr[maxIdx])
            {
                maxIdx = i;
            }
        }
        for (int i=0; i<size; ++i)
        {
            if (v[i] >= 0)
            {
                int l = numStr[i] - '0', r = numStr[v[i]]-'0';
                int diff = pow(10, size-1-i)*(r-l) - pow(10, size-1-v[i])*(r-l);
                num += diff;
                break;
            }
        }
        return num;
    }
};

int main()
{
    int num = 41223;
    Solution sol;
    auto res = sol.maximumSwap(num);
    cout << res << endl;
}
