#include <iostream>

#include <vector>
#include "linkedlist"

using namespace std;


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;

        vector<int> nodes;

        ListNode* tmp_head = head;
        while (tmp_head) {
            nodes.emplace_back(tmp_head->val);
            tmp_head = tmp_head->next;
        }

        ListNode* reversed_head = reverse(head);

        int half = nodes.size() / 2;
        for (int i=0; i<half; ++i) {
            if (nodes[i] != reversed_head->val) {
                return false;
            }
            reversed_head = reversed_head->next;
        }

        return true;
    }

    ListNode* reverse(ListNode* node) {
        ListNode *sentinel = new ListNode(-1, node);

        ListNode* pre = sentinel;
        ListNode* curr = sentinel->next;
        while (curr->next != nullptr) {
            ListNode* post = curr->next;
            curr->next = post->next;
            post->next = pre->next;
            pre->next = post;
        }

        return sentinel->next;
    }
};


int main() {
    ListNode* test_1 = makeLinkedList(1, 2, 3, 4, 5);

    ListNode* result;
    Solution s;
    result = s.reverse(test_1);
    printLinkedList(result);

    return 0;
}
