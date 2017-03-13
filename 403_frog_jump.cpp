#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_set>
#include <unordered_map>

// DP
// 1W. Keep a hashmap/ordered_map of reached stones
// 2. At stone i, find whether can be reached throught previous stones

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>> reached;
        if (stones.empty() || stones[0] != 0)   return false;
        
        // for each index, update the next jumpable by its previous
        reached[1] = {0};
        for (int i=1; i<stones.size(); ++i){
            int cur = stones[i];
            auto& prev = reached[cur];
            cout << "Using idx:" << cur << " as mid Stone ... " << endl;
            for (auto p:prev){
                int dis = cur-p;
                cout << "From idx: " << p << endl;
                for (int j=-1; j<=1; ++j){
                    int nx = cur + dis + j;
                    // only jump forward
                    if (nx > cur){
                        cout << "\t reached " << nx << endl;
                        reached[nx].insert(cur);
                    }
                }
            }
        }

        // either stones only contain '0', or last stone can be reached by prev stone
        return stones.size() == 1 || !reached[stones.back()].empty();
    }
};

int main(){
    Solution sol;

    vector<int> stones1 = {0,1};
    vector<int> stones2 = {0,1,3,5,7};
    vector<int> stones3 = {0,1,2,3,4,8,9,11};

    assert(sol.canCross(stones1) == true);
    assert(sol.canCross(stones2) == true);
    assert(sol.canCross(stones3) == false);

    return 0;
}
