#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = evenHead;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};


int main() {
    ListNode* test_1 = makeLinkedList(1, 2, 3, 4, 5);
    ListNode* test_2 = makeLinkedList(2, 1, 3, 5, 6, 4, 7);

    ListNode* result;
    Solution s;
    result = s.oddEvenList(test_1);
    printLinkedList(result);
    result = s.oddEvenList(test_2);
    printLinkedList(result);

    return 0;
}
