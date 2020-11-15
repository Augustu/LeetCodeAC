#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;

        bool is_new = true;
        int val = head->val;

        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            if (val == curr->val) {
                is_new = false;
            } else {
                is_new = true;
                val = curr->val;
            }
            if (is_new) {
                prev = curr;
                curr = curr->next;
            } else {
                curr = curr->next;
                prev = curr;
            }
        }

        return sentinel->next;
    }
};


int main() {
    return 0;
}
