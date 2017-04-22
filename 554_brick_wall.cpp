#include <iostream>
#include <vector>
#include <unordered_map>

// 1. Maintain a hashmap of all gaps
// 2. Scan through all gaps to find MAX
// 3. least bricks == height - MAX
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> gaps;
        for (auto&& row:wall){
            int cur_width = 0;
            int n = row.size();
            for (int i=0; i<n-1; ++i){
                cur_width += row[i];
                ++ gaps[cur_width];
            }
        } 
        // find the max of bricks gaps
        int max_gaps = 0;
        for (auto it = gaps.begin(); it != gaps.end(); ++it){
            max_gaps = max(max_gaps, it->second);
        }
        cout << "Max_gaps is : " << max_gaps << endl;
        return wall.size() - max_gaps;
    }
};

int main(){
    vector<vector<int>> wall = {
        {1, 2, 2, 3},
        {2,1, 3, 2},
        {3, 5}
    };
    Solution sol;
    auto res = sol.leastBricks(wall);
    cout << "Least Bricks is: " << res << endl;
    return 0;
}
