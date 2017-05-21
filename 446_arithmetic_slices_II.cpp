#include <iostream>
#include <vector>
#include <unordered_map>
// 1. Maintain a diff map <int, int> 
// 2. Update one by one
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        using diff_map_t = unordered_map<int, int>;
        vector<diff_map_t> diff_maps;
        int size = A.size(), res = 0;
        diff_maps.resize(size);
        for (int i=0; i<size; ++i){
            diff_map_t cur;
            for (int j=0; j<i; ++j){
                long diff = (long)A[i] - (long)A[j];
                if (diff <= INT_MIN || diff >= INT_MAX) continue;
                int dft = 0;
                if (diff_maps[j].find(diff) != diff_maps[j].end()){
                    dft = diff_maps[j][diff];
                }
                res += dft;
                cur[diff] += dft + 1;
            }
            diff_maps[i] = move(cur);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,1,2,3};
    auto res = sol.numberOfArithmeticSlices(nums);
    cout << "Res: " << res << endl;
    return 0;
}
