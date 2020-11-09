#include <iostream>

#include <linkedlist>

using namespace std;


typedef LinkNode<int> ListNode;


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        ListNode* head = new ListNode(0, l1);
        l1 = head->next;
        ListNode* pre = head;
        while (l1 != nullptr) {
            // TODO
            l1 = l1->next;
        }

        return head->next;
    }
};


int main() {
    LinkNode<int> *test_1 = makeLinkedList( 1, 2, 4);
    LinkNode<int> *test_2 = makeLinkedList( 1, 3, 4);

    Solution s;

    LinkNode<int> *head = s.mergeTwoLists(test_1, test_2);
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}