#include <iostream>

#include "linkedlist"

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

        ListNode* head = new ListNode(0);
        ListNode* current = head;
        while (l1 != nullptr && l2 != nullptr) {
            while (l1 != nullptr && l2 != nullptr
                && l1->val <= l2->val) {
                current->next = l1;
                current = current->next;
                l1 = l1->next;
            }
            while (l1 != nullptr && l2 != nullptr
                && l1->val > l2->val) {
                current->next = l2;
                current = current->next;
                l2 = l2->next;
            }
        }
        if (l1 != nullptr) {
            current->next = l1;
        }
        if (l2 != nullptr) {
            current->next = l2;
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