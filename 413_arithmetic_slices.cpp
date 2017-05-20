#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int res = 0, len = 0;
        for (int i=2; i<A.size(); ++i){
            if (A[i]-A[i-1] == A[i-1] - A[i-2]){
                ++len;
                res += len;
            }
            else{
                len = 0;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {0,4,5,6,9,12};
    Solution sol;
    auto res = sol.numberOfArithmeticSlices(nums);
    cout << "Total solution: " << res << endl;
    return 0;
}
