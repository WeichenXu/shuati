#include <iostream>
#include <vector>

// Implement different sorting algorithms
// 1. merge sort
// 2. quick sort
// 3. heap sort

using namespace std;

class Solution{
public:
    void mergeSortHelper(vector<int>& nums, int start, int end){
        if (start >= end){
            return;
        }
        // divide the array in halves, sort them seperately
        int mid = ((start + end) >> 1);
        mergeSortHelper(nums, start, mid);
        mergeSortHelper(nums, mid+1, end);

        // merge the two sorted lists
        // copy the left half only
        vector<int> left(nums.begin()+start, nums.begin()+mid+1);
        int cur=0, size = end-start+1;
        int i=start, j=mid+1;
        while(cur < size){
            if (i <= mid && j <= end){
                nums[start+cur] = left[i-start] < nums[j] ? left[i++ - start]:nums[j++];
            }
            else{
                nums[start+cur] = i>mid ? nums[j++]:left[i++ - start];
            }
            ++cur;
        }
        cout << endl;

        return;
    }

    void mergeSort(vector<int>& nums){
        mergeSortHelper(nums, 0, nums.size()-1);
        return;
    }
};

int main(){
    vector<int> nums = {-1, 3, -2, 1, 5, 6};
    //vector<int> nums = {1, -1};
    
    Solution sol;
    sol.mergeSort(nums);

    // print the result
    for(auto n:nums){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
