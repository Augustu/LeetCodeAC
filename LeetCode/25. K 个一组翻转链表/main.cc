#include <iostream>
#include <tuple>

#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* sentinel = new ListNode(-1, head);
        ListNode* tail = sentinel;
        ListNode* pre = sentinel;

        while (head) {
            for (int i=0; i<k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return sentinel->next;
                }
            }

            ListNode* post = tail->next;
            tie(head, tail) = reverseFromHead(head, k);
            pre->next = head;
            tail->next = post;
            pre = tail;
            head = post;
        }

        return sentinel->next;
    }

    pair<ListNode*, ListNode*> reverseFromHead(ListNode* head, int length) {
        ListNode* sentinel = new ListNode(-1, head);
        ListNode* pre = sentinel;
        ListNode* post = nullptr;
        // five elements only need four loops, ref: N92
        for (int i=1; i<length; ++i) {
            post = head->next;
            head->next = post->next;
            post->next = pre->next;
            pre->next = post;
        }
        return {sentinel->next, head};
    }
};


int main() {
    ListNode* test_1 = makeLinkedList(1,2,3,4,5);

    ListNode* result;
    Solution s;
    result = s.reverseKGroup(test_1, 2);
    printLinkedList(result);
    result = s.reverseKGroup(test_1, 3);
    printLinkedList(result);
}

