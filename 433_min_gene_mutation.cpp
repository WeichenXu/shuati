#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        // BFS in reverse way
        queue<string> q;
        int size = bank.size();
        unordered_map<string, bool> visited;
        unordered_map<string, unordered_map<string, bool>> connected;
        unordered_set<char> validChars={'A','C','G','T'};
        auto isConnected = [&](const auto& l, const auto& r)
        {
            int diff = 0, idx = -1;
            for (int i=0; i<8; ++i)
            {
                if (l[i] != r[i])   ++diff, idx = i; 
            }
            return diff==1 and validChars.find(l[idx]) != validChars.end() and validChars.find(r[idx]) != validChars.end();
        };
        for (int i=0; i<size; ++i)
        {
            visited[bank[i]] = false;
            for (int j=i+1; j<size; ++j)
            {
                if (isConnected(bank[i], bank[j]))
                {
                    connected[bank[i]][bank[j]] = true;
                    connected[bank[j]][bank[i]] = true;
                }
            }
        }
        if (visited.find(end) == visited.end()) return false;
        q.push(end);
        visited[end] = true;
        int res = 0;
        while (not q.empty())
        {
            queue<string> nx;
            while (not q.empty())
            {
                auto c = q.front();
                q.pop();
                if (isConnected(c, start))  return res+1;
                cout << res << ", " << c << endl; 
                for (const auto& cc:connected[c])
                {
                    if (not visited[cc.first])
                    {
                        visited[cc.first] = true;
                        nx.push(cc.first);
                        cout << res << ", push " << cc.first << endl; 
                    }
                }
            }
            ++res;
            swap(q, nx);
        }
        return -1;
    }
};

int main()
{
    string start = "AACCGGTT";
    string end = "AACCGGTA";
    //vector<string> bank={"AAAACCCC", "AAACCCCC", "AACCCCCC"};
    vector<string> bank = {};
    Solution sol;
    auto res = sol.minMutation(start, end, bank);
    cout << res << endl;
    return 0;
}
