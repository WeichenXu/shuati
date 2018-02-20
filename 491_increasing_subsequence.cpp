#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<string> resStr;
        unordered_set<string>resStrM;
        int size = nums.size();
        for (int i=1; i<size; ++i)
        {
            const int cur = nums[i];
            // 1. len >= 2
            const int len = res.size();
            for (int j=0; j<len; ++j)
            {
                if (res[j].back() <= cur)
                {
                    string nxStr = resStr[j] + to_string(cur)+",";
                    if (resStrM.find(nxStr) == resStrM.end())
                    {
                        resStrM.insert(nxStr);
                        vector<int> nxVec(res[j]);
                        nxVec.push_back(cur);
                        res.push_back(nxVec);
                        resStr.push_back(nxStr);
                    }
                }
            }
            // 2. len == 2
            for (int j=0; j<i; ++j)
            {
                const int pre = nums[j];
                if (pre <= cur)
                {
                    string ss = to_string(pre)+","+to_string(cur)+",";
                    if (resStrM.find(ss) == resStrM.end())
                    {
                        resStrM.insert(ss);
                        res.push_back({pre, cur});
                        resStr.push_back(ss);
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums{4,6,7,7};
    Solution sol;
    auto res = sol.findSubsequences(nums);
    for (auto& str:res)
    {
        for (auto s:str){
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
