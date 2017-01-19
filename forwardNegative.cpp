#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    /*
    vector<int> removeNegative(vector<int> &nums){
        int i=0, j=nums.size()-1;
        while(i < j){
            if (nums[j] < 0){
                swap(nums[i++], nums[j--]);
            }
            --j;
        }
        return nums;
    }
    */

    // maintain the negative nums in-order
    vector<int> removeNegative(vector<int> &nums){
        int i=0, j=0;
        int size = nums.size();
        while(i < size){
            if (nums[i] < 0){
                swap(nums[i], nums[j++]);
            }
            ++i;
        }
        return nums;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> nums = {{}, {1}, {-1,1}, {1,-1}, {1,-2,-1,3}};
    for (int i=0; i<nums.size(); ++i){
        auto res = sol.removeNegative(nums[i]);
        for (auto n:res){
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
