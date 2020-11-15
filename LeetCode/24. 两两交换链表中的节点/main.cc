#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !(head->next)) return head;

        ListNode* sentinel = new ListNode(-1, head);
        ListNode* pre = sentinel;
        ListNode* current = head;
        while (current && current->next) {
            ListNode* post = current->next->next;
            pre->next = current->next;
            current->next->next = current;
            current->next = post;
            pre = current;
            current = current->next;
        }

        return sentinel->next;
    }
};


int main() {
    return 0;
}
