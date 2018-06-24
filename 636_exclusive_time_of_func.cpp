#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> tokenize(const string& str, const char ch=':')
    {
        vector<string> tokens;
        stringstream ss(str);
        string token;
        while (getline(ss, token, ch))
        {
            tokens.push_back(token);
        }
        return tokens;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int>s;
        int preTime = 0;
        for(const auto& log:logs)
        {
            auto tokens = tokenize(log);
            int id = stoi(tokens[0]), time = stoi(tokens[2]);
            if (not s.empty()) res[s.top()] += time-preTime;
            if (tokens[1] == "start")
            {
                s.push(id);
                preTime = time;
            }
            else    
            {
                ++res[id];
                s.pop();
                preTime = time+1;
            }
        }
        return res;
    }
};

int main()
{
    vector<string> logs={
        "0:start:0",
        "0:end:0",
        "0:start:1",
        "1:start:5",
        "1:end:8",
        "0:end:9",
    };
    Solution sol;
    auto res = sol.exclusiveTime(2, logs);
    for (auto t:res) cout << t << " ";
    cout << endl;
    return 0;
}
