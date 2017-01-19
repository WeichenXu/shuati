#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

// 1. count the occurances of the elements
// 2. get the most k frequent pairs using priority queue 

using namespace std;

class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        using node_t = pair<int, int>;
        unordered_map<int, int> dict;
        // get the count of the number
        for (int n:nums){
            ++dict[n]; 
        }

        // get the most k frequent elements
        auto cmp = [](const node_t& lhs, const node_t& rhs){return lhs.second > rhs.second;};
        using queue_t = priority_queue<node_t, vector<node_t>, decltype(cmp)>;
        queue_t q(cmp);
        for (auto it:dict){
            if (q.size() < k){
                q.push({it.first, it.second});
            }
            else{
                int smallest = q.top().second;
                if (it.second > smallest){
                    q.pop();
                    q.push({it.first, it.second});
                }
            }
        }
        
        // return the list of the k most frequent elements
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top().first);
            q.pop();
        }

        return res;
    }
};

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 4, 3, 4};
    int k=3;
    Solution sol;
    auto topK = sol.topKFrequent(nums, k);
    for (int i=0; i<topK.size(); ++i){
        cout << topK[i] << " ";
    }
    cout << endl;
    return 0;
}
