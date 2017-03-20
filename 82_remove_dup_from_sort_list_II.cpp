#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 1. recursive: remove any duplicate at beginning
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        auto *origin = head;
        while (head->next && head->next->val == head->val){
            head = head->next;
        }
        //cout << (void*) origin << ", " << (void*) head << endl;
        if (origin != head){
            head = head->next;
        }
        else{
            head->next = deleteDuplicates(head->next);
            return head;
        }
        //cout << "head find dups, now head is " << head->val << endl;
        return deleteDuplicates(head);
    }
    
    void printList(ListNode* head){
        while(head){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main(){
    ListNode *first = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(2);
    first->next = second, second->next = third;
    Solution sol;
    sol.printList(first);
    auto *res = sol.deleteDuplicates(first);
    sol.printList(res);
    return 0;
}
