#include <iostream>

#include "linkedlist"

using namespace std;

/*
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* node = head;
        while (node->next) {
            if (node->val == val) {
                node->val = node->next->val;
                node->next = node->next->next;
                break;
            }
            // check the last one
            if (node->next->next == nullptr && node->next->val == val) {
                node->next = nullptr;
                break;
            }
            node = node->next;
        }
        return head;
    }
};
*/


class Solution {
public:
    // fast slow pointers
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* sentinel = new ListNode(-1, head);
        ListNode* fast = sentinel->next;
        ListNode* slow = sentinel;
        while (fast) {
            if (fast->val == val) {
                slow->next = fast->next;
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return sentinel->next;
    }
};


int main() {
    ListNode* test_1 = makeLinkedList(4,5,1,9);

    ListNode* result;
    Solution s;

    result = s.deleteNode(test_1, 9);
    printLinkedList(result);
    result = s.deleteNode(test_1, 5);
    printLinkedList(result);
    result = s.deleteNode(test_1, 1);
    printLinkedList(result);
    result = s.deleteNode(test_1, 9);
    printLinkedList(result);
    result = s.deleteNode(test_1, 4);
    printLinkedList(result);

    return 0;
}

