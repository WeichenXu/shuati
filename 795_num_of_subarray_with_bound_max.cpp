#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        const int size = A.size();
        int lastMatch = -1, lastUnMatch = -1, res = 0;
        for (int i=0; i<size; ++i)
        {
            if (A[i] < L)
            {
                res += max(0, lastMatch - lastUnMatch);
            }
            else if (A[i] > R)
            {
                lastUnMatch = i;
            }
            else
            {
                lastMatch = i;
                res += lastMatch - lastUnMatch;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> A = {2,1,4,3};
    Solution sol;
    auto res = sol.numSubarrayBoundedMax(A, 2, 3);
    cout << res << endl;
    return 0;
}
