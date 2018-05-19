#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        const int size = A.size();
        unordered_map<int, int> map;
        vector<long> m(size, 1);

        const int mod = pow(10,9)+7;
        sort(A.begin(), A.end());
        for (int i=0; i<size; ++i) map[A[i]] = i;
        for (int i=1; i<size; ++i)
        {
            int num = A[i];
            for (int j=i-1; j>=0; --j)
            {
                int first = A[j];
                if (num%first)  continue;
                int second = num/first;
                auto it = map.find(second);
                if (it == map.end())   continue;
                m[i] += m[j]*m[it->second];
                m[i] %= mod; 
            }
            cout << "ith:" << i << ", val:" << m[i] << endl;
        }
        int res = 0;
        for (const auto n:m)
        {
            res += n;
            res %= mod;
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {18,3,6,2};
    Solution sol;
    auto res = sol.numFactoredBinaryTrees(nums);
    cout << res << endl;
}
