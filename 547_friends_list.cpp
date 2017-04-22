#include <iostream>
#include <vector>

// 1. union-find
// 2. compress the path

using namespace std;

class Solution {
private:
    // Utility Function//
    // unino two friends if they have different root
    void union_helper(int l, int r){
        int rootL = find(l), rootR = find(r);
        if (rootL != rootR){
            int &lenL = len_[l], &lenR = len_[r];
            if (lenL <= lenR){
                root_[rootL] = rootR;
                ++lenL;
            }
            else{
                root_[rootR] = rootL;
                ++lenR;
            }
        }
        return;
    }

    // return the root of the node
    int find(int i){
        if (root_[i] != i){
            root_[i] = find(root_[i]);
        }
        return root_[i];
    }

    vector<int> root_;
    vector<int> len_;
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        root_.resize(n);
        for (int i=0; i<n; ++i){
            root_[i] = i;
        }
        len_.resize(n, 0);
        for(int i=0; i<n; ++i){
            for (int j=0; j<=i; ++j){
                if (i != j && M[i][j]){
                    union_helper(i, j);
                }
            }
        }
        // return the count of (-1) node
        int res = 0;
        for (int i=0; i<n; ++i){
            if (root_[i] == i){
                ++res;
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> relationships = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    Solution sol;
    auto res = sol.findCircleNum(relationships);
    cout << "The friends circle count: " << res << endl;
    return 0;
}
