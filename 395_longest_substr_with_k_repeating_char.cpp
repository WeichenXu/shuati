#include <iostream>
#include <string>

using namespace std;

// Divide and conquer
class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = s.length();
        int result = 0;
        for (int i=0; i<=len-k; ++i)
        {
            int cnt[26] = {0};
            int mask = 0, lastMatch=i;
            // find local longest 
            for (int j=i; j<len; ++j)
            {
                int idx = s[j]-'a';
                ++cnt[idx];
                if (cnt[idx] < k) 
                {
                    mask |= (1<<idx);
                }
                else
                {
                    mask &= (~(1<<idx));
                }
                if (not mask)
                {
                    lastMatch = j;
                    result = max(result, j-i+1);
                }
            }
            // we could skip overlapping with local longest
            i = lastMatch;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string s(385,'s');
    cout << sol.longestSubstring(s, 1) << endl;
    cout << s.length() << endl;
    return 0;
}
