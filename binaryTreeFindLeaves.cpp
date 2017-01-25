#include <iostream>
#include <vector>
#include <map>

// the level of the node == the height of the node

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left{nullptr}, *right{nullptr};
    TreeNode(int x) : val(x){}
};

class Solution{
private:
    map<int, vector<int>> leaves;
public:
    // return the height, insert node using post-order traverse
    int helper(TreeNode* cur){
        if (cur == nullptr){
            return 0;
        }
        int h = max(helper(cur->left), helper(cur->right));
        leaves[h].push_back(cur->val);
        return h+1;
    }

    vector<vector<int>> findLeaves(TreeNode* root){
        helper(root);

        // construct the result vector
        vector<vector<int>> res;
        for (auto it = leaves.begin(); it != leaves.end(); ++it){
            res.push_back(move(it->second));
        } 

        return res;
    }
};

int main(){
    TreeNode* root = new TreeNode(0), *left = new TreeNode(-1), *right = new TreeNode(1);
    root->left = left, root->right = right;
    Solution sol;
    auto res = sol.findLeaves(root);
    cout << "All levels: " << res.size() << endl;
    for (const auto&r:res){
        for (auto num:r){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
