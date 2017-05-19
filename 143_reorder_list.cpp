#include <iostream>

// 1. reverse the second half list
// 2. merge them together

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr){}
};

void printList(ListNode* head);

class Solution{
public:
    void reorderList(ListNode* head){
        if (head == nullptr) return;
        // Find the middle of the list using slow/fast pointers
        ListNode* slow = head,* fast = slow;
        while (fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        // Reverse the second half list
        ListNode* prev = nullptr;
        ListNode* second = slow->next;
        slow->next = nullptr;
        while (second != nullptr){
            ListNode* tmp = second;
            second = second->next;
            tmp->next = prev;
            prev = tmp;
        }
        
        // Merge the two half list
        ListNode* first = head, *tmp = nullptr;
        second = prev;
        while(second != nullptr){
            tmp = first;
            first = first->next;
            tmp->next = second;
            tmp = second;
            second = second->next;
            tmp->next = first;
        }
    }
};

void printList(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    ListNode first(1), second(2), third(3), fourth(4);
    first.next = &second;
    second.next = &third;
    //third.next = &fourth;
    //fourth.next = nullptr;
    Solution sol;
    cout << "Pre reverse: " << endl;
    printList(&first);
    sol.reorderList(&first);
    cout << "After reverse: " << endl;
    printList(&first);
    return 0;
}


