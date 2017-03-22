#include <iostream>
#include <vector>

// k-length maximum number = i-len max from nums1 MERGE k-i-len max from nums2 

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        int m = nums1.size(), n = nums2.size();
        cout << "-----Size of both nums-----" << endl;
        cout << "nums1: " << m << ", nums2: " << n << endl;
        if (m + n < k)  return res;
        for (int i=max(0, k-n); i<=min(k, m); ++i){
            cout << "------When k1 is: " << i << endl;
            auto cur = mergeArray(maxArray(nums1, i), maxArray(nums2, max(0, k-i)));
            cout << "------Merged: " << endl;
            print(cur);
            res = larger(cur, res, 0, 0) ? cur:res;
            cout << "------After: " << endl;
            print(res);
        }
        return res;
    }

private:
    //-- Utility Function --//
    bool larger(const vector<int>& left, const vector<int>& right, int l, int r){
        int m = left.size(), n = right.size();
        while (l < m && r < n){
            if (left[l] > right[r]) return true;
            if (left[l] < right[r]) return false;
            ++l, ++r;
        }
        return r == n;
    }

    // Max Array: largest k-bits number in order
    vector<int> maxArray(const vector<int> &nums, int k){
        vector<int> res(k, 0);
        int n = nums.size();
        for (int i=0, j=0; i<n; ++i){
            while(j > 0 && n-i+j > k && res[j-1] < nums[i]) --j;
            if (j < k) res[j++] = nums[i];
        }
        print(res);
        return res; 
    }

    // Merge Arrays: given two arrays, output largest merged array
    vector<int> mergeArray(const vector<int> &nums1, const vector<int> &nums2){
        int m = nums1.size(), n = nums2.size();
        vector<int> res(m+n, 0);
        int i=0, j=0, len = m+n;
        while (i+j < len){
            int cur = i+j;
            res[cur] = larger(nums1, nums2, i, j) ? nums1[i++] : nums2[j++];
        }
        return res;
    }

    void print(vector<int>& nums){
        for (auto n:nums){
            cout << n << " ";
        }
        cout << endl;
    }
};

int main(){
    vector<int> nums1 = {3,3,3,2,3,7,3,8,6,0,5,0,7,8,9,2,9,6,6,9,9,7,9,7,6,1,7,2,7,5,5,1};
    vector<int> nums2 = {5,6,4,9,6,9,2,2,7,5,4,3,0,0,1,7,1,8,1,5,2,5,7,0,4,3,8,7,3,8,5,3,8,3,4,0,2,3,8,2,7,1,2,3,8,7,6,7,1,1,3,9,0,5,2,8,2,8,7,5,0,8,0,7,2,8,5,6,5,9,5,1,5,2,6,2,4,9,9,7,6,5,7,9,2,8,8,3,5,9,5,1,8,8,4,6,6,3,8,4,6,6,1,3,4,1,6,7,0,8,0,3,3,1,8,2,2,4,5,7,3,7,7,4,3,7,3,0,7,3,0,9,7,6,0,3,0,3,1,5,1,4,5,2,7,6,2,4,2,9,5,5,9,8,4,2,3,6,1,9};
    Solution sol;
    auto res = sol.maxNumber(nums1, nums2, 160);
    for (auto n:res){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
