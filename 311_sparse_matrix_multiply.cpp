#include <iostream>
#include <vector>

// Multiply two matrix M = A.B
// M[i][j] = sum(A[i] * B[j])

// Since it is a sparse matrix, whenever we find a non-zero A[i1][j1], add to res
using namespace std;

class Solution{
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B){
        int rowA = A.size(), colA = A[0].size();
        int rowB = B.size(), colB = B[0].size();
        vector<vector<int>> res;
        if (!rowA || colA != rowB || !colB){
            return res;
        }
        
        // resize the result
        res.resize(rowA);
        for (int i=0; i<rowA; ++i){
            res[i].resize(colB);
        }

        // locate non-zero in A
        for (int i=0; i<rowA; ++i){
            for (int j=0; j<colA; ++j){
                // add the offset to res
                if (A[i][j]){
                    for (int k=0; k<colB; ++k){
                        res[i][k] += A[i][j]*B[j][k];
                    }
                }
            }
        }

        return res;
    }
};

int main(){
    using matrix_t = vector<vector<int>>;
    matrix_t A = {
        {1, 0, 0}, 
        {-1, 0, 3}
    };
    matrix_t B = {
        {7, 0, 0},
        {0, 0, 0},
        {0, 0, 1}
    };
    Solution sol;
    auto res = sol.multiply(A, B);
    for (auto &row:res){
        for (auto& n:row){
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
