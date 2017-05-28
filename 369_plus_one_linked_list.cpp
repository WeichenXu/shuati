#include <iostream>

// 1. Reverse the linked list
// 2. Add one using the carrier

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (head == nullptr)    return head;
        // Reverse the linked list
        head = reverseList(head);
        
        // Add one using carrier
        int carrier = 1;
        auto* cur = head, * prev = cur;
        while(cur != nullptr){
            if (!carrier)   break;
            cur->val += carrier;
            carrier = cur->val / 10;
            cur->val %= 10;
            prev = cur;
            cur = cur->next;
        }
        if (carrier){
            ListNode* last = new ListNode(1);
            prev->next = last;
        }

        return reverseList(head);
    }

    ListNoe* reverseList(ListNode* head){
        if (head == nullptr)    return head;
        ListNode* nx = head->next;
        while(nx != nullptr){
            ListNode* tmp = nx->next;
            nx->next = head;
            head = nx;
            nx = tmp;
        }
        return head;
    }
};
