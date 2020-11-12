#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* sentinel = new ListNode(-1);
        ListNode* current = sentinel;

        while (head) {
            ListNode* post = head->next;

            ListNode* shadow_head = sentinel->next;
            while (shadow_head) {
                if (head->val == shadow_head->val) {
                    break;
                }
                shadow_head = shadow_head->next;
            }

            // shadow_head == nullptr, means not found val
            // should add val to list
            if (!shadow_head) {
                current->next = head;
                head->next = nullptr;

                current = head;
            }

            head = post;
        }

        return sentinel->next;
    }
};


// TODO add map to speed up


int main() {
    ListNode* test_1 = makeLinkedList(1,2,3,3,2,1);
    ListNode* test_2 = makeLinkedList(1,1,1,1,2);

    ListNode* result;
    Solution s;
    result = s.removeDuplicateNodes(test_1);
    printLinkedList(result);
    result = s.removeDuplicateNodes(test_2);
    printLinkedList(result);

    return 0;
}
