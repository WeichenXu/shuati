#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// from left to right
// at s[i]
// iterate s[j] (s[j] == s[i] && j < i)
// ++ count if palindrom(s[j+1, i-1])
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        // each single letter substr
        int res = len;
        bool flag[len][len];
        memset(flag, false, sizeof(bool)*len*len);

        unordered_map<char, vector<int>> m;
        for (int i=0; i<len; ++i)
        {
            flag[i][i] = true;
            auto& v = m[s[i]];
            for (auto pre:v)
            {
                if (pre == i-1 || flag[pre+1][i-1])
                {
                    flag[pre][i] = true;
                    ++res;
                }
            }
            v.push_back(i);
        }

        return res;
    }
};

int main()
{
    string s = "";
    Solution sol;
    auto res = sol.countSubstrings(s);
    cout << res << endl;
    return 0;
}
