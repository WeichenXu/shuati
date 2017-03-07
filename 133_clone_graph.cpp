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
// 1. copy all the new nodes, keep map between <origin node*, copy node*>
// 2. iterate all new nodes, relink the neighbors
struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*> q;
        if (node == nullptr){
            return node;
        }
        
        // First iteration
        q.push(node);
        auto* copy = new UndirectedGraphNode(node->label);
        m[node] = copy;
        while(! q.empty()){
            auto* cur = q.front();
            q.pop();
            // Iterate all the neighbors 
            for (auto* nb:cur->neighbors){
                if (m.find(nb) == m.end()){
                    q.push(nb);
                    copy = new UndirectedGraphNode(nb->label);
                    m[nb] = copy;
                }
                // copy the link
                m[cur]->neighbors.push_back(m[nb]);  
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
