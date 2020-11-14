#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        ListNode* start = head;

        int length = 1;
        while (head->next) {
            length++;
            head = head->next;
        }
        // make list a loop
        head->next = start;

        k = length - k%length -1;
        while (k--) {
            start = start->next;
        }

        ListNode* new_head = start->next;
        start->next = nullptr;

        return new_head;
    }
};


int main() {
    return 0;
}
