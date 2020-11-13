#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // TODO fix this, i'm confused :(
        if (!head) return head;

        ListNode* anchor = head;
        ListNode* tmp = head->next;
        int length = 0;
        while (tmp) {
            length++;
            anchor = anchor->next;
            tmp = tmp->next;
        }

        ListNode* pre = head;
        ListNode* curr = head->next;
        for (int i=1; i<length; ++i) {
            if (i%2) {
                cout << curr->val << endl;
                // odd, move this to tail
                ListNode* tmp = curr->next;
                anchor->next = curr;
                anchor = anchor->next;

                curr->next = nullptr;
                curr = tmp;
                pre->next = curr;
            } else {
                pre = pre->next;
                curr = curr->next;
            }
            
        }

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
