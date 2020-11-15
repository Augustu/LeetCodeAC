#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* prev = nullptr;
        int carry = 0;
        while (l1 && l2) {
            int tmp = l1->val + l2->val + carry;
            l1->val = tmp % 10;
            carry = tmp / 10;

            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1) {
            while (l1) {
                int tmp = l1->val + carry;
                l1->val = tmp % 10;
                carry = tmp / 10;
                prev = l1;
                l1 = l1->next;
            }
        }
        if (l2) {
            while (l2) {
                int tmp = l2->val + carry;
                l2->val = tmp % 10;
                carry = tmp / 10;
                prev->next = l2;
                prev = l2;
                l2 = l2->next;
            }
        }

        if (carry) {
            prev->next = new ListNode(carry);
        }

        return head;
    }
};


// TODO beautify the if checks, make if into little blocks
// https://leetcode-cn.com/submissions/detail/123510101/


int main() {
    return 0;
}
