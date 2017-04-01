#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int l = 0, r = 0;
        sort (nums1.begin(), nums1.end());
        sort (nums2.begin(), nums2.end());
        unordered_set<int> intersect;

        while (l < m && r < n){
            int l_val = nums1[l], r_val = nums2[r];
            if (l_val == r_val){
                intersect.insert(l_val);
            }
            if (l_val <= r_val){
                ++l;
            }
            else{
                ++r;
            }
        }
        
        vector<int> res;
        for (auto i:intersect){
            res.push_back(i);
        }

        return res;
    }
};

int main(){
    vector<int> left = {3,1,3,4,5};
    vector<int> right = {-1,3,1,6};
    Solution sol;
    auto res = sol.intersection(left, right);
    for (auto i:res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
