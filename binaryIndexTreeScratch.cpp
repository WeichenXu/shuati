#include <iostream>
#include <vector>

// 1. build binary index tree 
//    sum can be represented by 1+2+4+8+16 ...
// 2. get the range sum in O(lgn) time
//        Improve: binary search to get index >= lower, index <= higher

class Solution{
public:
    int countRangeSum(vector<int>& nums, int lower, int higher){
        // init the binary index tree
        n_ = nums.size() + 1;
        sum.resize(n_, 0);
        for (int i=0; i<n_-1; ++i){
            update(i, 0, nums[i]);
        }

        // 
    }
private:
    int n_{0};
    using num_t = vector<int>;
    num_t sum;
    
    //-- utility function --/
    void update(int i, int pre, int cur){
        int diff = cur - pre;
        ++i;
        while(i <= n_){
            sum[i] += diff;
            i += i&(-i);
        }
    }

    // input in 0 based
    int sum(int i){
        ++i;
        int res = 0;
        while(i > 0){
            res += sum[i];
            i &= (i-1);
        }
        return res;
    }
};

int main(){

}
