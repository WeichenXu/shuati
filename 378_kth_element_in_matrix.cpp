#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct node{
        int m_r{0}, m_c{0}, m_val{0};
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // BFS from top-left point
        auto cmp = [&](const auto& l, const auto& r){return l.m_val > r.m_val;};
        priority_queue<node, vector<node>, decltype(cmp)> q(cmp);

        // insert first row
        int rows = matrix.size(), cols = matrix[0].size();
        for (int i=0; i<cols; ++i)
        {
            q.push({0, i, matrix[0][i]});
        }
        for (int i=1; i<k; ++i)
        {
            auto& cur = q.top();
            if (cur.m_r < rows-1)
            {
                q.push({cur.m_r+1, cur.m_c, matrix[cur.m_r+1][cur.m_c]});
            }
            q.pop();
        }
        return q.top().m_val;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1,5,10},
        {6,6,10},
        {7,20,31}
    };
    Solution sol;
    auto res = sol.kthSmallest(matrix, 4);
    cout <<  res << endl;
}
