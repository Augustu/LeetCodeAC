#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;
        ListNode* pre = sentinel;
        ListNode* curr = head;

        while (curr) {
            if (curr->val == val) {
                curr = curr->next;
                pre->next = curr;
            } else {
                pre = pre->next;
                curr = curr->next;
            }
        }

        return sentinel->next;
    }
};


int main() {
    return 0;
}
