#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // BFS
        auto toStr = [](const auto& board){
            string res = "";
            for (const auto& row : board)
            {
                for (auto ele : row) res += to_string(ele) + "->"; 
            }
            return res;
        };
        vector<vector<int>> target = {{1,2,3}, {4,5,0}};
        const auto targetStr = toStr(target);
        queue<vector<vector<int>>> q;
        q.push(board);
        int res = 0;
        vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while (not q.empty())
        {
            queue<vector<vector<int>>> nx;
            while (not q.empty())
            {
                auto& cur = q.front();
                auto curStr = toStr(cur);
                if (curStr == targetStr) return res;
                if (m_visited.find(curStr) == m_visited.end())
                {
                    cout << "visiting: " << curStr << endl;
                    m_visited.insert(curStr);
                    int i = 0, j = 0;
                    for (int r=0; r < 2; ++r)
                    {
                        for (int c=0; c < 3; ++c)
                        {
                            if (cur[r][c] == 0)
                            {
                                i = r, j = c;
                                break;
                            }
                        }
                    }
                    for (int k = 0; k<dirs.size(); ++k)
                    {
                        int n_i = i+dirs[k].first, n_j = j+dirs[k].second;
                        if (n_i < 0 or n_i >= 2 or n_j < 0 or n_j >= 3)  continue;
                        auto nxBoard = cur;
                        swap(nxBoard[n_i][n_j], nxBoard[i][j]);
                        nx.push(nxBoard);
                        cout << "lvl: " << res << ", " << toStr(nxBoard) << endl;
                    }
                }
                q.pop();
            }
            ++res;
            swap(q,nx);
        }
        return -1;
    }
    unordered_set<string> m_visited;
};

int main()
{
    Solution sol;
    vector<vector<int>> board = {{4,1,2}, {5,0,3}};
    auto res = sol.slidingPuzzle(board);
    cout << res << endl;
    return 0;
}
