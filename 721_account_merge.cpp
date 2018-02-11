#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    // union and find
    int Find(int i)
    {
        if (m_acctName[i] != i)
        {
            int root = Find(m_acctName[i]);
            m_acctName[i] = root;
        }
        return m_acctName[i];
    }

    void Union(int i, int j)
    {
        int iRoot = Find(i), jRoot = Find(j);
        if (iRoot != jRoot)
        {
            int iHeight = m_height[iRoot], jHeight = m_height[jRoot];
            if (iHeight > jHeight)
            {
                m_acctName[jRoot] = iRoot;
                m_height[jRoot] = jRoot+1;
            }
            else
            {
                m_acctName[iRoot] = jRoot;
                m_height[iRoot] = iRoot+1;
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int size = accounts.size();
        m_acctName.resize(size, -1);
        m_height.resize(size, 1);
        // union all accts 
        for (int i=0; i<size; ++i)
        {
            m_acctName[i] = i;
            const auto& emails = accounts[i];
            for (int j=1; j<emails.size(); ++j)
            {
                const auto& email = emails[j];
                auto it = m_emailMap.find(email);
                if (it != m_emailMap.end())
                {
                    Union(it->second, i); 
                }
                m_emailMap[email] = i;
            }
        }
        // construct ans
        unordered_map<int, set<string>> ans;
        for (auto it:m_emailMap)
        {
            ans[Find(it.second)].emplace(it.first);
        }
        vector<vector<string>> res;
        for (auto it:ans)
        {
            vector<string> all(it.second.begin(), it.second.end());
            all.emplace(all.begin(), accounts[it.first][0]);
            res.emplace_back(all);
        }
        return res;
    }
private:
    unordered_map<string, int> m_emailMap;
    vector<int> m_acctName;
    vector<int> m_height;
};

int main()
{
    Solution sol;
    vector<vector<string>> accts;
    auto res = sol.accountsMerge(accts);
    return 0;
}
