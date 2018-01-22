#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// We enumerate all possible solution
// Choose minimum distance from all answers
// Two kinds of candidates
// 1. fixed length: middle str palindrom +-1, 0
// 2. length changed: 999..9, 10.01

class Solution {
public:
    string nearestPalindromic(string n) {
        vector<long> candidates;
        int len = n.length();
        string left = n.substr(0, len%2 == 0?(len/2):(len/2+1));
        long leftInt = stol(left);
        for (long i=-1; i<=1;++i)
        {
            long tmp = leftInt + i;
            if (tmp < 0)
            {
                continue;
            }
            string tmpStr = to_string(tmp);
            string candidate = tmpStr;
            reverse(tmpStr.begin(), tmpStr.end());
            candidates.push_back(stol(candidate + (len%2 == 0?(tmpStr):(tmpStr.substr(1)))));
        }

        // for kind 2
        if (len >= 2)
        {
            candidates.push_back(pow(10,(len-1))-1);
        }
        candidates.push_back(pow(10,len)+1);

        // find answer
        long dis = LONG_MAX, res = LONG_MAX;
        for (const auto l:candidates)
        {
            cout << "candidate: " << l << endl;
            const auto cur = labs(l-stol(n));
            if (cur && ((cur < dis) || (cur == dis && l < res)))
            {
                dis = cur;
                res = l;
            }
        }

        return to_string(res); 
    }
};

int main()
{
    Solution sol;
    string n = "1213";
    auto res = sol.nearestPalindromic(n);
    cout << res << endl;
    return 0;
}
