#include <iostream>

#include <stack>
#include "linkedlist"

using namespace std;


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a1, a2;

        while (l1) {
            a1.emplace(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            a2.emplace(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* ans = nullptr;
        while (!a1.empty() || !a2.empty() || carry) {
            int a = a1.empty() ? 0 : a1.top();
            if (!a1.empty()) a1.pop();
            int b = a2.empty() ? 0 : a2.top();
            if (!a2.empty()) a2.pop();

            int curr = a+b+carry;
            carry = curr / 10;
            curr = curr % 10;

            // ans = new ListNode(curr, ans);
            ListNode* tmp = new ListNode(curr);
            tmp->next = ans;
            ans = tmp;
        }

        return ans;
    }
};


int main() {
    return 0;
}
