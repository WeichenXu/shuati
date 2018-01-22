#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        helper(path, 1, k, n);
        return res;
    }
    void helper(vector<int>& cur, int idx, int remainNum, int remainSum)
    {
        if (!remainSum & !remainNum)
        {
            res.push_back(cur);
        }
        if (idx > remainSum || idx>9 || !remainNum)
        {
            return;
        }
        cur.push_back(idx);
        helper(cur, idx+1, remainNum-1, remainSum-idx);
        cur.pop_back();
        helper(cur, idx+1, remainNum, remainSum);
    }
    vector<vector<int>> res;
};

int main()
{
    int k = 2, n =18;
    Solution sol;
    auto res = sol.combinationSum3(k, n);
    for (const auto& vs:res)
    {
        for (const auto v:vs)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
