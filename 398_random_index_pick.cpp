#include <stdlib.h>

#include <iostream>
#include <vector>

#include <utility>
#include <time.h>

// 1. reservior sampling

using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        n = move(nums);
    }

    int pick(int target) {
        srand(time(NULL));
        int count = 0, res = -1;
        for (int i=0; i<n.size(); ++i){
            if (n[i] == target){
                ++count;
                int r = rand()%count;
                if (! r){
                    res = i;
                }
            }
        }
        return res;
    }
private:
    vector<int> n;
};

int main(){
    vector<int> nums = {1,1,2,1,1,3,2};
    Solution sol(nums);
    int n = 1;
    cout << "Pick " << n << " at " << sol.pick(n) << endl;
    return 0;
}

