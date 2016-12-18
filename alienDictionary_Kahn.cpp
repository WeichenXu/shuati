#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
// Use topological sort

using namespace std;

class Solution {
private:
    using graph_t = unordered_map<char, unordered_set<char>>;
    using in_orders_t = unordered_map<char, int>;
    using queue_t = queue<char>;

    graph_t graph;
    queue_t queue;
    in_orders_t in_orders;

    // utility functino
    // print the graph
    void printGraph(graph_t &graph){
        for(const auto&node:graph){
            cout << "Node: " << node.first << " -> ";
            const auto & next = node.second;
            for (auto n:next){
                cout << n << " ";
            }
            cout << endl;
        }
    }

    // topological sort using kahn
    // 1. calculate in_order for all nodes
    // 2. enque the empty in_order nodes
    // 3. deque the nodes and update the in_order neighbours
    // 4. traverse all the nodes, count the number
    string topologicalSort(graph_t& graph){
        // helper
        printGraph(graph);

        // initialize
        int count = 0;
        string order = "";
        // calculate the in_orders
        for (const auto & node:graph){
            char s = node.first;
            if (in_orders.find(s) == in_orders.end()){
                in_orders[s] = 0;
            }
            auto & next = node.second;
            for (const auto & n:next){
                ++in_orders[n];
            }
        }
        // enque all in_order == 0 nodes
        for (const auto & it:in_orders){
            if (it.second == 0){
                queue.push(it.first); 
            }
        }
        while (!queue.empty()){
            char cur = queue.front();
            queue.pop();
            ++count;
            order += cur;
            // update all cur neighbours
            const auto& next = graph[cur];
            for (const auto & n:next){
                --in_orders[n];
                if (in_orders[n] == 0){
                    queue.push(n);
                }
            }
        }
        // it the count does not match, no topo order
        return (count == graph.size())?order:"";
    }

public:
    string alienOrder(vector<string>& words){
        if (words.empty()){
            return "";
        }
        graph.clear();
        unordered_set<char> sentinel;
        // add first word into graph
        auto& first = words[0];
        // add relationship
        for (int i=0; i<words.size(); ++i){
            for (char c:words[i]){
                if (graph.find(c) == graph.end())
                    graph[c] = sentinel;
            }
            if(i == 0){
                continue;
            }
            
            auto& pre = words[i-1];
            auto& cur = words[i];
            int len = min(pre.length(), cur.length());
            int j;
            for (j=0; j<len; ++j){
                if (pre[j] != cur[j]){
                    break;
                }
            }
            if (j == len){
                if (cur.length() < pre.length()){
                    return "";
                }
                continue;
            }
            if (graph.find(pre[j]) == graph.end()){
                graph[pre[j]] = sentinel;
            }
            cout << "Idx: " << i << endl;
            printGraph(graph);
            graph[pre[j]].insert(cur[j]);
            printGraph(graph);
        }
        return topologicalSort(graph);
    }

};

int main(){
    Solution sol;
    vector<string> dict = {"wrt", "wrf", "er", "ett", "rftt"};
    vector<string> dict2 = {"z", "z"}; 
    vector<string> dict3 = {"aac", "aabb", "aaba"};
    cout << "Ans: \n" << sol.alienOrder(dict2) << endl;
    return 0;
}
