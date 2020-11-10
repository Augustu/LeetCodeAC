#include <iostream>

#include "linkedlist"

using namespace std;

/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};
*/


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};


int main() {
    ListNode* test_1 = makeLinkedList(1,2,3,4,5);

    ListNode* result;
    Solution s;
    result = s.reverseList(test_1);
    printLinkedList(result);

    return 0;
}

