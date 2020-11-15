#include <iostream>

#include "linkedlist"
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;

        ListNode* curr = head;
        while (curr) {
            ListNode* post = curr->next;
            curr->next = nullptr;
            insertNode(sentinel, curr);
            curr = post;
        }

        return sentinel->next;
    }

    ListNode* insertNode(ListNode* head, ListNode* node) {
        // head is a sentinel here
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            if (curr->val > node->val) {
                prev->next = node;
                node->next = curr;
                break;
            }

            prev = prev->next;
            curr = curr->next;
        }

        if (!curr) {
            prev->next = node;
            node->next = nullptr;
        }

        return head;
    }
};


// TODO speed up this


int main() {
    return 0;
}
