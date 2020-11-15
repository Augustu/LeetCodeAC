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

        ListNode* first = nullptr;
        ListNode* second = nullptr;
        if (diff > 0) {
            first = headA;
            second = headB;
        } else {
            diff = -diff;
            first = headB;
            second = headA;
        }


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

    int getLength(ListNode *head) {
        ListNode *tmp = head;
        int length = 0;
        while (tmp) {
            tmp = tmp->next;
            length++;
        }
        return length;
    }
};


int main() {
    return 0;
}
