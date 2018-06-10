#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
private:
    vector<int> m_ids;
public:
    int Find(int i)
    {
        if (m_ids[i] == -1) return i;
        int parent = Find(m_ids[i]);
        m_ids[i] = parent;
        return parent;
    }
    void Union(int i, int j)
    {
        int lRoot = Find(i), rRoot = Find(j);
        if (lRoot != rRoot)
        {
            m_ids[lRoot] = rRoot;
        }
    }
    int numSimilarGroups(vector<string>& A) {
        const auto size = A.size();
        m_ids.resize(size, -1);
        int res = 0;
        auto isSimilar = [](const auto& l, const auto& r)
        {
            int diff = 2, len = l.length();
            for (int i=0; i<len; ++i)
            {
                if (l[i] != r[i])   --diff;
                if (diff < 0)   return false;
            }
            return not diff;
        };
        for (int i=0; i<size; ++i)
        {
            for (int j=i+1; j<size; ++j)
            {
                if (Find(i) != Find(j) and isSimilar(A[i], A[j]))
                {
                    cout << "union: " << A[i] << " with " << A[j] << endl;
                    Union(i, j);
                }
            }
        }
        for (auto id:m_ids) cout << id << " ";
        cout << endl;
        return accumulate(m_ids.begin(), m_ids.end(), 0, [](int init, int v){return v == -1?++init:init;});
    }
};

int main()
{
    Solution sol;
    vector<string> strs = {
        "tars", "rats", "star", "arts", "arst"
    };
    auto res = sol.numSimilarGroups(strs);
    cout << res << endl;
}
