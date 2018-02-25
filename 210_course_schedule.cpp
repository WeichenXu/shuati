#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

//https://leetcode.com/problems/course-schedule-ii/discuss/59316/20+-lines-C++-BFSDFS-Solutions

using namespace std;

/* DFS
class Solution{
    public:
        vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
            // 1. build graph
            edges.resize(numCourses);
            visited.assign(numCourses, false);
            for (auto& pre:prerequisites)
            {
                edges[pre.first].insert(pre.second);
            }
            // 2. dfs all header
            for (int i=0; i<numCourses; ++i)
            {
                curPath.assign(numCourses, false);
                if (dfs(i))
                    return {};
            }
            return res;
        }
    private:
        // return true if dfs find cycle
        bool dfs(int cur)
        {
            // curPath help stop cycle
            if (visited[cur]) return false;
            visited[cur] = curPath[cur] = true;
            for (auto nx:edges[cur])
            {
                // check nx even visited
                if (curPath[nx] || dfs(nx))
                {
                    cout << cur << "->" << nx << endl;
                    return true;
                }
            }
            // remove cur from visiting path
            curPath[cur] = false;
            res.push_back(cur);
            return false;
        }
        vector<int> res;
        vector<bool> visited;
        vector<bool> curPath;
        vector<unordered_set<int>> edges;
};
*/

// BFS
class Solution{
    public:
        vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
            // 1. build graph
            edges.resize(numCourses);
            inDegree.assign(numCourses, 0);
            for (auto& pre:prerequisites)
            {
                auto p = edges[pre.first].insert(pre.second);
                if (p.second){++inDegree[pre.second];}
            }
            // 2. find all header, when in-degree == 0, all dependency have been removed
            queue<int> header;
            for (int i=0; i<numCourses; ++i)
            {
                if (not inDegree[i]) header.push(i);
            }
            // 3. bfs all header
            while (not header.empty())
            {
                auto head = header.front();
                header.pop();
                res.push_back(head);
                for (auto nx : edges[head])
                {
                    if (--inDegree[nx] == 0) {header.push(nx);}
                }
            }
            if (res.size() != numCourses) {res.clear();}
            reverse(res.begin(), res.end());
            return res;
        }
    private:
        vector<int> res;
        vector<int> inDegree;
        vector<unordered_set<int>> edges;
};

int main()
{
    vector<pair<int,int>> pre = {
        {5,8},{3,5}, {1,9}, {4,5},{0,2},{1,9},{7,8},{4,9}
    };
    int num = 10;
    Solution sol;
    auto res = sol.findOrder(num, pre);
    for (auto i:res)
    {
        cout << i << " ";
    }
    cout << endl;
}
