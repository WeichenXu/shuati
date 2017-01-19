#include <iostream>

using namespace std;

// three cases for deleting a bst node
// 1. deleting the leaf node
// 2. deleting node has single child
// 3. deleting node has two children

class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
public:
    TreeNode* deleteNode(TreeNode* root, int key){
        if (root == nullptr){
            return root;
        }
        if (key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val){
            root->left = deleteNode(root->left, key);
        }
        // if root is our targeted node
        else{
            // case 1
            if (root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            // case 2 & 3
            if (root->left == nullptr){
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            else {
                // set root to previous one
                TreeNode* left = root->left;
                while(left){
                    left = left->right;
                }
                root->val = left->val;
                root->left = deleteNode(root->left, root->val);
            }
        }
        return root;
    }
    
    void print(TreeNode* root){
        if (root == nullptr){
            return;
        }
        print(root->left);
        cout << root -> val << " ";
        print(root->right);
    }
};

int main(){
    Solution sol;

    TreeNode *root = new TreeNode(0);
    TreeNode *left = new TreeNode(-1);
    TreeNode *right = new TreeNode(1);
    
    cout << "Original: ";
    sol.print(root);
    cout << endl;

    sol.deleteNode(root, -1);
    cout << "Delete left: ";
    sol.print(root);
    cout << endl;

    sol.deleteNode(root, 0);
    cout << "Delete root: ";
    sol.print(root);
    cout << endl;
    
    sol.deleteNode(root, 1);
    cout << "Delete right: ";
    sol.print(root);
    cout << endl;
    
    sol.deleteNode(root, 11);
    cout << "Delete none: ";
    sol.print(root);
    cout << endl;

    return 0;
}
