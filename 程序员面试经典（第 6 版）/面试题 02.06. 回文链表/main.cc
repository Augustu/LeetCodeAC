#include <iostream>

#include <vector>
#include "linkedlist"

using namespace std;


/*
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nodes;
        while (head) {
            nodes.emplace_back(head->val);
            head = head->next;
        }

        int length = nodes.size();
        int half = length / 2;
        for (int i=0; i<half; ++i) {
            if (nodes[i] != nodes[length-i-1]) {
                return false;
            }
        }

        return true;
    }
};
*/


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast) {
            slow = slow->next;
        }

        slow = reverse(slow);

        while (slow) {
            if (slow->val != head->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }

        return true;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* post = curr->next;
            curr->next = pre;
            pre = curr;
            curr = post;
        }
        return pre;
    }
};


int main() {
    return 0;
}
