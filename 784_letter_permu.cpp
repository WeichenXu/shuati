#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<int> letterIdx;
        for (int i=0; i<S.length(); ++i)
        {
            char ch = S[i];
            if (ch >= '0' and ch<= '9') continue;
            else letterIdx.push_back(i);
            S[i] = tolower(ch);
        }
        const int len = letterIdx.size();
        int size = (1<<len);
        vector<string> res;
        for (int i=0; i<size; ++i)
        {
            string ss = S;
            for (int j=0; j<len; ++j)
            {
                if ((i >> j)&0x1)   ss[letterIdx[j]] = toupper(ss[letterIdx[j]]);
            }
            res.push_back(ss);
        }
        return res;
    }
};

int main()
{
    string S = "123ab456";
    Solution sol;
    auto res = sol.letterCasePermutation(S);
    for (const auto& s:res) cout << s <<" ";
    cout << endl;
    return 0;
}
