#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // TODO fix this
        return reverseFromHead(head, k);
    }

    ListNode* reverseFromHead(ListNode* head, int length) {
        ListNode* sentinel = new ListNode(-1, head);
        ListNode* pre = sentinel;
        ListNode* post = nullptr;
        for (int i=0; i<length; ++i) {
            post = head->next;
            head->next = post->next;
            post->next = pre->next;
            pre->next = post;
        }
        printLinkedList(sentinel);
        return sentinel->next;
    }
};


int main() {
    ListNode* test_1 = makeLinkedList(1,2,3,4,5);

    ListNode* result;
    Solution s;
    result = s.reverseKGroup(test_1, 5);
    printLinkedList(result);
    // result = s.reverseKGroup(test_1, 3);
    // printLinkedList(result);
}

