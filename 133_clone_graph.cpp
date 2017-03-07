#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *   int label;
 *   vector<UndirectedGraphNode *> neighbors;
 *   UndirectedGraphNode(int x) : label(x) {};
 * };
 */

// Two iterations
// 1. BFS
// 2. DFS

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr){
            return node;
        }
        if (m.find(node) == m.end()){
            auto* copy = new UndirectedGraphNode(node->label);
            m[node] = copy;
            for (auto* nb:node->neighbors){
                copy->neighbors.push_back(cloneGraph(nb));
            }
        }
        return m[node];
    }
};

int main(){
    Solution sol;
    UndirectedGraphNode* zero = new UndirectedGraphNode(0);
    UndirectedGraphNode* one = new UndirectedGraphNode(1);
    zero->neighbors.push_back(one);

    sol.cloneGraph(zero);
    return 0;
}
