#include <iostream>
#include <vector>

// F(k) = F(k-1) + sum - n*B_k(0)
using namespace std;

class Solution{
public:
    int maxRotateFunction(vector<int>& A) {
        int s = A.size();
        long sum = 0, f = 0;
        for (int i=0; i<s; ++i){
            f += i*A[i];
            sum += A[i];
        }

        long res = f;
        for (int i=s-1; i>=0; --i){
            f += sum - s*A[i];
            res = max(res, f);
        }
        return res;
    }
};

int main(){
    vector<int> nums = {4,3,2,6};
    Solution sol;
    cout << sol.maxRotateFunction(nums) << endl;
    return 0;
}
