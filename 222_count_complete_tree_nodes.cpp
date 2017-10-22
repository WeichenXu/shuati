#include <queue>

// recursive
class Solution {
public:
    int height (TreeNode* cur){
        return cur == nullptr ? -1:1+height(cur->left);
    }
    int countNodes(TreeNode* root) {
        int h = height(root);
        return h < 0 ? 0:
            height(root->right) == h-1? (1<<h) + countNodes(root->right):(1<<(h-1))+countNodes(root->left);

    }
};
// iterative

class Solution {
public:
    int height (TreeNode* cur){
        return cur == nullptr ? -1:1+height(cur->left);
    }
    int countNodes(TreeNode* root) {
        int h = height(root), nodes = 0;
        while (root != nullptr)
        {
            if (height(root->right) == h-1)
            {
                nodes += 1 << h;
                root = root->right;
            }
            else
            {
                nodes += 1 << h;
                root = root->left;
            }
            --h;
        }
        return nodes;
    }
};
