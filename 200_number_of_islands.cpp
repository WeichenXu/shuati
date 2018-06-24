#include <iostream>
#include <vector>

using namespace std;

// Union-find
// flat path & path compression
class Solution {
public:
    inline int to1d(int i, int j){
        return (i*col_+j);
    }
    // Union
    void Union(int left, int right){
        int left_idx = find(left);
        int right_idx = find(right);
        if (levels_[left_idx] < levels_[right_idx]){
            parents_[left_idx] = right_idx;
        }
        else{
            if (levels_[left_idx] == levels_[right_idx]){
                ++levels_[left_idx];
            }
            parents_[right_idx] = left_idx;
        }
    }

    // find
    int find(int idx){
        if (parents_[idx] == idx){
            return idx;
        }
        int parent = find(parents_[idx]);
        parents_[idx] = parent;
        return parent;
    }

    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        row_ = m, col_ = n;
        parents_.resize(m*n);
        levels_.resize(m*n);
        fill_n(levels_.begin(), m*n, 0);
        fill_n(parents_.begin(), m*n, -1);
        int islands = 0;
        // init result
        vector<int> res;
        // init neighbour steps
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        for (const auto& p:positions){
            cout << "Processing position, idx: " << p.first << " " << p.second << endl; 
            ++islands;
            int idx = to1d(p.first, p.second);
            parents_[idx] = idx;
            // get all neighbour lands
            for (int i=0; i<dx.size(); ++i){
                int ni = p.first + dx[i];
                int nj = p.second + dy[i];
                int nidx = to1d(ni, nj);
                if (ni >= 0 && ni < row_ && nj >= 0 && nj < col_ && parents_[nidx] != -1){
                    cout << "\tLand Neighbour, idx: " << ni << " " << nj << endl;
                    if (find(idx) != find(to1d(ni, nj))){
                        --islands;
                        Union(idx, to1d(ni, nj));
                    }
                }
            }
            res.push_back(islands);
        }
        return res;
    }
private:
    // map the ocean&island
    vector<int> parents_;
    vector<int> levels_;
    int row_, col_;
};

int main(){
    Solution sol;
    int m = 5, n = 5;
    vector<pair<int, int>> lands;
    // insert the land
    lands.emplace_back(0,0);
    lands.emplace_back(1,1);
    lands.emplace_back(0,1);
    lands.emplace_back(3,4);
    lands.emplace_back(3,3);
    //cout << "Size of the lands:" << lands.size() << endl; 
    auto res = sol.numIslands2(m, n, lands);
    for (const auto l:res){
        cout << l << " ";
    }
    cout << endl;
    return 0;
}

