#include <iostream>
#include <vector>

using namespace std;

// 1. recursively

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        size_t len = input.length();
        vector<int> res;
        for (size_t i = 0; i<len; ++i)
        {
            char ch = input[i];
            if (ch == '+' || ch == '-' || ch == '*')
            {
                string str1 = input.substr(0, i);
                vector<int> diff1 = diffWaysToCompute(move(str1));
                string str2 = input.substr(i+1);
                vector<int> diff2 = diffWaysToCompute(move(str2));
                res.reserve(diff1.size() * diff2.size());

                // enumarate possible solutions
                for (auto num1 : diff1)
                {
                    for (auto num2 : diff2)
                    {
                        switch (ch){
                        case '+':
                            res.push_back(num1+num2);
                            break;
                        case '-':
                            res.push_back(num1-num2);
                            break;
                        case '*':
                            res.push_back(num1*num2);
                        default:
                            break;
                        }
                    }
                }
            }
        }

        // return atoi if input is a pure number
        if (res.empty())
        {
            res.push_back(atoi(input.c_str()));
        }
        return res;
    }
};

int main(){
    string str = "2*3-4*5";
    Solution sol;
    auto res = sol.diffWaysToCompute(str);
    for (const auto& str:res)
    {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
