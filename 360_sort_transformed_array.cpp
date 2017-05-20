#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int size = nums.size();
        vector<int> sorted(nums.size(), 0);
        if (!size) return sorted;
        float pivot;
        if (!a) pivot = b > 0 ? nums[size-1] : nums[0];
        else pivot = - (float)b/(2.0 * (float)a);
        
        int l = 0, r = size-1, i=0;
        while (l <= r){
            if (fabs((float)nums[l] - pivot) >= fabs((float)nums[r] - pivot)){
                sorted[i++] = nums[l++];
            }
            else    sorted[i++] = nums[r--];
        }

        if (a > 0) reverse(sorted.begin(), sorted.end());
        for (auto& n:sorted){
            n = doCalculate(n, a, b, c);
        }
        return sorted;
    }
private:
    int doCalculate(int n, int a, int b, int c){
        return a*n*n + b*n + c;
    }
};

int main(){
    vector<int> nums = {-4, -2, 2, 4};
    Solution sol;
    auto res = sol.sortTransformedArray(nums, 1, 3, 5);
    for (auto n:res){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
