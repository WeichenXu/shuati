class Solution {
// cache key position in inorder
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0, 0, preorder.length()-1, preorder, inorder);        
    }
    TreeNode* helper(int preStart, int inStart, int inEnd, const vector<int>& preOrder, const vector<int>& inOrder)
    {
        if (preStart >= preOrder.length() || inStart > inEnd)   return nullptr;
        TreeNode* node = new TreeNode(preOrder[preStart]);
        int index = inStart;
        for (;index <= inEnd; ++index)
        {
            if (inOrder[index] == preOrder[preStart]) break;
        }
        node->left = helper(preStart+1, inStart, index-1, preOrder, inOrder);
        node->right = helper(preStart+index-inStart+1, index+1, inEnd, preOrder, inOrder);
        return node;
    }
};
