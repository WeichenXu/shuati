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
    // 2. iterative:
    ListNode* deleteDuplicates(ListNode* head) {
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
