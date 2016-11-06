#include <iostream>
using namespace std;

class ListNode{
public:
    ListNode* next{nullptr};
    int val{0};
    ListNode (int val_, ListNode* next_):
        next(next_), val(val_){}
};

ListNode* reverseList(ListNode* l){
    if (l == nullptr || l->next == nullptr){
        return l;
    }
    ListNode* newHead = reverseList(l->next);
    l->next->next = l;
    l->next = nullptr;
    return newHead;
}

void printList(ListNode* l){
    while(l != nullptr){
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

int main(){
    ListNode *third = new ListNode(3, nullptr);
    ListNode *second = new ListNode(2, third);
    ListNode *first = new ListNode(1, second);
    printList(first);
    cout << "reversed" << endl;
    first = reverseList(first);
    printList(first);
    return 0;
}
