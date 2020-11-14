#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->next;
    }
};


int main() {
    return 0;
}
