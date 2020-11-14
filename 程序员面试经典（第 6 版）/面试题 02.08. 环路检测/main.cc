#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !(head->next)) {
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                break;
            }
        }

        if (fast != slow) {
            return nullptr;
        }

        int pos = 0;
        while (head != slow) {
            head = head->next;
            slow = slow->next;
            pos++;
        }

        return head;
    }
};


int main() {
    return 0;
}
