#include <iostream>
#include <array>
#include <vector>
#include <cmath>

#define DOUBLE_EQ(a, b) (fabs(a-b) < eps)

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> doubleNums;
        for (auto num:nums)
        {
            doubleNums.push_back(static_cast<double>(num));
        }
        return helper(doubleNums);
    }
    bool helper(vector<double> nums)
    {
        static constexpr array<char, 4> m_ops = {'+', '-', '*', '/'};
        //if (m_finded) return m_finded;
        if (nums.size() == 1)   return DOUBLE_EQ(nums[0], target);
        for (int i=0; i<nums.size(); ++i)
        {
            for (int j=0; j<nums.size(); ++j)
            {
                if (i == j) continue;
                auto l = nums[i], r = nums[j];
                vector<double> res;
                for (int k = 0; k<nums.size(); ++k)
                {
                    if (k != i and k != j)  res.push_back(nums[k]);
                }
                for (auto op:m_ops)
                {
                    switch(op){
                        case '+':
                            if (i > j) res.push_back(l + r);
                            else continue;
                            break;
                        case '*':
                            if (i > j) res.push_back(l * r);
                            else continue;
                            break;
                        case '-':
                            res.push_back(l - r);
                            break;
                        case '/':
                            if (not DOUBLE_EQ(r, 0.0))  res.push_back(l/r);
                            else continue;
                            break;
                    }
                    if (helper(res))    return true;
                    res.pop_back();
                }
            }
        }
        return false;
    }
private:
    //bool m_finded{false};
    static constexpr double eps = 1e-5;
    static constexpr double target = 24.0;
};

int main()
{
    Solution sol;
    //vector<int> nums = {4,1,8,7};
    vector<int> nums = {1,2,1,2};
    cout << boolalpha << sol.judgePoint24(nums) << endl;
    return 0;
}
