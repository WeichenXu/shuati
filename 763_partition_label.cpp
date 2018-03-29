#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map <char, int> mm;
        for (int i=0; i<S.length(); ++i)    mm[S[i]] = i; 
        vector<int> res;
        for (int i=0; i<S.length(); ++i)
        {
            int right = mm[S[i]], left = i;
            for (; i<right; ++i) right = max(right, mm[S[i]]);
            res.push_back(right - left+1);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "abceeee";
    auto res = sol.partitionLabels(s);
    for (auto r:res)
    {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}
