#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        int lenA = getLength(headA);
        int lenB = getLength(headB);
        int diff = lenA - lenB;

        ListNode* first = diff >= 0 ? headA : headB; // >= and < import here
        ListNode* second = diff < 0 ? headA : headB;
        diff = diff > 0 ? diff : -diff;

        while (diff--) {
            first = first->next;
        }

        while (first) {
            if (first == second) {
                return first;
            }
            first = first->next;
            second = second->next;
        }

        return nullptr;
    }

    int getLength(ListNode* head) {
        ListNode* tmp = head;
        int length = 0;
        while (tmp) {
            length++;
            tmp = tmp->next;
        }
        return length;
    }
};


int main() {
    return 0;
}
