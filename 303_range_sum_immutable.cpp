#include <iostream>
#include <vector>

// sum[i] = sum[0 to i-1]
// sumRange(i, j) = sum[j+1] - sum[i]
using namespace std;

class NumArray {
private:
    vector<int> sum_helper;
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        sum_helper.resize(n+1, 0);
        for (int i=0; i < n; ++i){
            sum_helper[i+1] = sum_helper[i] + nums[i];
        }
        for (auto sum:sum_helper){
            cout << sum << " ";
        }
        cout << endl;
    }

    int sumRange(int i, int j) {
        return sum_helper[j+1] - sum_helper[i];
    }
};

/**
 *  * Your NumArray object will be instantiated and called as such:
 *   * NumArray obj = new NumArray(nums);
 *    * int param_1 = obj.sumRange(i,j);
 *     */

int main(){
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray obj(nums);
    int i= 0, j = 2;
    auto res = obj.sumRange(i, j);
    cout << "Range sum is " << res << endl;
    return 0;
}
