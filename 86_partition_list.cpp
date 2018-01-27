class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = nullptr,* right = nullptr;
        ListNode* leftHead = left, * rightHead = right;
        while (head != nullptr)
        {
            auto* nx = head->next;
            if (head->val < x)
            {
                if (left == nullptr)
                {
                    left = head;
                    leftHead = left;
                }
                else
                {
                    left->next = head;
                    left = left->next;
                }
            }
            else
            {
                if (right == nullptr)
                {
                    right = head;
                    rightHead = right;
                }
                else
                {
                    right->next =head;
                    right = right->next;
                }
            }
            head = nx; 
        }
        if (leftHead != nullptr)
        {
            left->next = rightHead;
        }
        else
        {
            leftHead = rightHead;
        }
        if (right != nullptr)
        {
            right->next = nullptr;
        }
        return leftHead;
    }
};
