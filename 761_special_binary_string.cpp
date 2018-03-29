#include <iostream>
#include <string>
#include <vector>

using namespace std;

// split S into vector of "special binary" seperated by 0
// https://leetcode.com/problems/special-binary-string/discuss/113211/Easy-and-Concise-Solution-with-Explanation-C++JavaPython

class Solution {
public:
    string makeLargestSpecial(string S) {
        vector<string> sub;
        for (int i=0; i<S.length(); ++i)
        {
            // advance one "1"
            int j=i+1;
            int cnt = 1;
            while (cnt)
            {
                if (S[j++] == '1') ++cnt;
                else --cnt;
            }
            sub.push_back(move("1"+makeLargestSpecial(S.substr(i+1, j-2-i))+"0"));
            i = j-1;
        }
        sort(sub.begin(), sub.end());
        string res = "";
        for (auto rit=sub.rbegin(); rit!=sub.rend(); ++rit) res+=*rit;
        return res;
    }
};

int main()
{
    Solution sol;
    auto res = sol.makeLargestSpecial("11011000");
    cout << res << endl;
}
