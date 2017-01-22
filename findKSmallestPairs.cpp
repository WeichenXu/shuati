#include <iostream>
#include <vector>
#include <queue>

// 1. Do not use two pointers
// 2. Keep K current smallest elements using Heap
//    push the idx with current+1 pair
//    pop the head of the heap

using namespace std;

class Solution{
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
        auto cmp = [](vector<int>& l, vector<int>& r){return (l[0]+l[1]) > (r[0]+r[1]);};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> que(cmp);
        int len1 = nums1.size(), len2 = nums2.size();
        vector<pair<int, int>> res;
        if (!len1 || !len2 || !k){
            return res;
        }
        
        // insert the first k candidates into the priority_queue
        for (int i=0; i<len1 && i<k; ++i){
            que.push({nums1[i], nums2[0], 0});
        }

        // pop the smallest element until matches k or queue is empty
        while(k-- && !que.empty()){
            auto cur = que.top();
            res.push_back({cur[0], cur[1]});
            int nx = cur[2]+1;
            que.pop();
            if (nx < len2){
                que.push({cur[0], nums2[nx], nx});
            }
        }

        return res;
    } 
};

int main(){
    Solution sol;
    vector<int> nums1 = {1,7,11}, nums2 = {2,4,6};
    auto res = sol.kSmallestPairs(nums1, nums2, 3);
    for (const auto&pair:res){
        cout << pair.first << ", " << pair.second << endl;
    }
    return 0;
}
