class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        auto* cur = root;
        int count = 0;
        while (cur != nullptr)
        {
            ++count;
            cur = cur->next;
        }
        int size = count/k, remain = count%k;
        vector<ListNode*> res(k, nullptr);
        for(int i=0; i<k; ++i)
        {
            if (root == nullptr)    break;
            res[i] = root;
            int steps = i<remain?size+1:size;
            for (int j=0; j<steps; ++j) 
            {
                if (j == steps-1)
                {
                    auto* nx = root->next;
                    root->next = nullptr;
                    root = nx;
                }
                else root = root->next;
            }
        }
        return res;
    }
};
