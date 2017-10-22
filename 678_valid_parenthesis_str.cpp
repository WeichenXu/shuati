#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool helper(const string& s, const char left, const char right) {
        int leftNum = 0;
        int starCnt = 0;
        for (auto ch:s)
        {
            if (ch == '*'){
                ++ starCnt;
            }
            else if(ch == left){
                ++ leftNum;
            }
            else if(ch == right){
                if (leftNum)
                {
                    -- leftNum;
                    continue;
                }
                if (starCnt)
                {
                    --starCnt;
                    continue;
                }
                return false;
            }
        }
        return leftNum <= starCnt;
    }

    bool checkValidString(string s)
    {
        // unpaired '('
        int low = 0, high = 0;
        for (const auto ch:s)
        {
            switch (ch)
            {
                case '(':
                    ++ low, ++ high;
                    break;
                case '*':
                    if (low > 0)
                    {
                        --low;
                    }
                    ++high;
                    break;
                case ')':
                    if (low > 0)
                    {
                        --low;
                    }
                    --high;
                    break;
            }
            if (high < 0)
            {
                return false;
            }
        }
        return low == 0;
    }
};

int main()
{
    Solution sol;
    vector<string> ss = {
        "()",
        "(*)",
        "(()",
        ")()",
        "*()",
        "*)",
        "((*)(*))((*"
    };
    for (const auto& str:ss)
    {
        cout << str << ", " << sol.checkValidString(str) << endl; 
    }
    return 0;
}
