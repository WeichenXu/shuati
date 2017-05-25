#include <iostream>

// Recursive and Bottom-Up
using namespace std;

/**
 *  * Definition for a binary tree node.
*/
struct TraverseInfo {
    int size(0);
    int lo(0);
    int hi(0);
    TraverseInfo(){}
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        TraverseInfo info;
        validBST(root, info);
        return maxSize;
    }
private:
    int maxSize = 0;
    void validBST(TreeNode* root, TraverseInfo& info){
        if (root == nullptr){
            info.lo = INT_MAX;
            info.hi = INT_MIN;
            return;
        }

        TraverseInfo left, right;
        validBST(root->left, left);
        validBST(root->right, right);
        if (left.size < 0 || right.size < 0 || root->val <= left.hi || root->val >= right.lo){
            info.size = -1;
            return;
        }
        info.size = 1 + left.size + right.size;
        info.lo = min(left.lo, root->val);
        info.hi = max(right.hi, root->val);
        maxSize = max(maxSize, size);
        return;
    }
};


