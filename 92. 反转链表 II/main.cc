#include <iostream>

#include "linkedlist"

using namespace std;


/*
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return head;

        ListNode* node = new ListNode(-1, head);
        head = node;
        int pos = 1;
        while (node) {
            // when equal the next node is the beginning to be reversed
            if (pos == m) {
                node->next = reverseFromHead(node->next, n-m+1);
                break;
            }

            node = node->next;
            pos++;
        }

        return head->next;
    }

    ListNode* reverseFromHead(ListNode* head, int length) {
        ListNode* pre = nullptr;
        ListNode* post = nullptr;
        ListNode *current = head;
        while (length-- && current) {
            post = current->next;
            current->next = pre;
            pre = current;
            current = post;
        }
        head->next = current;
        return pre;
    }
};
*/


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* sentinal = new ListNode(-1, head);
        ListNode* pre = sentinal;
        for (int i=1; i<m; ++i) {
            pre = pre->next;
        }

        head = pre->next;

        /* 1. pre -> head -> post -> follow
         * 
         * 2. pre -> head    post -> follow
         *            └----------------┘
         * 
         *            ┌-------┐
         *            ↓       |
         * 3. pre -> head    post -> follow
         *            │                ↑
         *            └----------------┘
         * 
         *             ┌-------┐
         *             ↓       |
         * 4. pre    head    post -> follow
         *     │       │      ↑         ↑
         *     |       └------┼---------┘
         *     └--------------┘
         * 
        */ 
        for (int i=m; i<n; ++i) {
            ListNode* post = head->next;
            head->next = post->next; // 2
            post->next = pre->next; // 3
            pre->next = post; // 4
        }

        return sentinal->next;
    }
};


int main() {
    ListNode* test_1 = makeLinkedList(1,2,3,4,5);

    ListNode* result;
    Solution s;
    result = s.reverseBetween(test_1, 2, 4);
    printLinkedList(result);
    result = s.reverseBetween(result, 1, 4);
    printLinkedList(result);
    result = s.reverseBetween(result, 3, 5);
    printLinkedList(result);

    return 0;
}
