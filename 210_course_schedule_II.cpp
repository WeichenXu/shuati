#include <iostream>
#include <vector>
#include <unordered_map>
// Conduct DFS on the graph

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        visited.resize(numCourses, 0);
    
        // 1. convert prerequisites to edges
        unordered_map<int, vector<int>> edges;
        for (auto& preq:prerequisites){
            edges[preq.first].push_back(preq.second);
        }
        // 2. Topological sort the graph
        vector<int> path;
        for (int i=0; i<numCourses; ++i){
            if (! dfs_helper(edges, path, i)){
                return {};
            }
        }
        return order;
    }
private:
    vector<int> order;
    vector<int> visited;
    // return false if cycle detected
    bool dfs_helper(unordered_map<int, vector<int>>& edges, vector<int>& path, int cur){
        // 1. if cur is already in the path before
        for (auto i:path){
            if (i == cur)   return false;
        }
        if (visited[cur]){
            return true;
        }
        visited[cur] = 1;
        auto& nx = edges[cur];
        // 2. iterate all neighbors
        path.push_back(cur);
        for (auto n:nx){
            if (! dfs_helper(edges, path, n))   return false;
        }
        path.pop_back();
        // 3. push cur into the order
        order.push_back(cur);
        return true;
    }
};

int main(){
    Solution sol;
    int numCourses = 5;
    vector<pair<int, int>> prerequisites = {
        {3,2},
        {3,1},
        {1,0},
        {2,0}
    };
    auto order = sol.findOrder(numCourses, prerequisites);
    cout << "Order should be: " << endl;
    for (auto i:order){
        cout << i << " >> ";
    }
    cout << endl;
    return 0;
}
