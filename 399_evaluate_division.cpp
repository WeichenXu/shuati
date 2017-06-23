#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// 1. Store the weighted path
// 2. Use DFS

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        // Build the graph
        for (int i=0; i<equations.size(); ++i){
            auto& p = equations[i];
            graph[p.first][p.second] = values[i];
            if (values[i]){
                graph[p.second][p.first] = 1.0/values[i];
            }
        }

        vector<double> res;
        // Query the graph
        int query_size = queries.size();
        res.resize(query_size);
        for (int i=0; i<query_size; ++i){
            visited.clear();
            double val = dfs(queries[i].first, queries[i].second);
            res[i] = ( val == 0 ? -1.0 : val); 
        }

        return res;
    }

private:
    unordered_map<string, unordered_map<string, double>> graph;
    unordered_set<string> visited;
    //bool connected{false};
    //double val;
    double dfs(const string& src, const string& dst){
        if (visited.find(src) == visited.end()){
            visited.insert(src);
            for (const auto& nx : graph[src]){
                if (nx.first == dst){
                    return nx.second;
                }            
                double nx_val = dfs(nx.first, dst);
                if (nx_val){
                    return nx.second*nx_val;
                }
            }
        }
        return 0;
    }
};

int main(){
    Solution sol;
    vector<pair<string, string>> equations = {
        {"a", "b"},
        {"b", "c"}
    };
    vector<double> vals = {2.0, 3.0};
    vector<pair<string, string>> queries = {
        {"a", "c"},
        {"b", "a"},
        {"a", "e"},
        {"a", "a"},
        {"x", "x"}
    };
    
    auto res = sol.calcEquation(equations, vals, queries);
    for (const auto val:res){
        cout << "Val: " << val << endl;
    }
    return 0;
}
