#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /*
    string pushDominoes(string dominoes) {
        const int size = dominoes.length();
        vector<pair<int, char>> v;
        for (int i=0; i<size; ++i)
        {
            if (dominoes[i] == 'L' || dominoes[i] == 'R')
                v.push_back({i, dominoes[i]});
        }
        const int vSize = v.size();
        int pre=-1;
        for (int i=0; i<vSize; ++i)
        {
            auto& p = v[i];
            cout << "visiting " << p.first << endl;
            if (p.second == 'L')
            {
                if (pre == -1 || dominoes[pre] == 'L')
                {
                    for (int j=pre+1; j<p.first; ++j)   dominoes[j] = 'L';
                }
                else
                {
                    int l=pre, r = p.first;
                    while (r-l > 2)
                    {
                        dominoes[++l] = 'R';
                        dominoes[--r] = 'L';
                    }
                }
            }
            else
            {
                if (i == vSize - 1)
                {
                    for (int j=p.first+1; j<size; ++j)    dominoes[j] = 'R';
                }
                if (i != -1 and dominoes[pre] == 'R')
                {
                    for (int j=pre+1; j<p.first; ++j)   dominoes[j] = 'R';
                }
            }
            pre = p.first;
        }
        return dominoes;
    }
    */
    // https://leetcode.com/problems/push-dominoes/discuss/132332/C++JavaPython-Two-Pointers
};

int main()
{
    //string ss = ".L...R..R...L..L..R.";
    string ss = ".L...R..R...L..L..R.";
    Solution sol;
    auto res = sol.pushDominoes(ss);
    cout << res << endl;
    return 0;
}
