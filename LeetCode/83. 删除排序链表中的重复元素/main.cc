#include <iostream>

#include "linkedlist"
#include <unordered_map>

using namespace std;


/* forget this is a sorted linked list
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next)) return head;

        unordered_map<int, bool> unique;

        ListNode* pre = head;
        unique.insert(pair<int, bool>(head->val, true));

        ListNode* current = head->next;
        while (current) {
            unordered_map<int, bool>::iterator iter = unique.find(current->val);
            if (iter != unique.end()) {
                pre->next = current->next;
            } else {
                unique.insert(pair<int, bool>(current->val, true));
                pre = pre->next;
            }
            current = current->next;
        }

        return head;
    }
};
*/


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !(head->next)) return head;

        ListNode* pre = head;
        ListNode* current = head->next;
        while (current) {
            if (pre->val == current->val) {
                pre->next = current->next;
            } else {
                pre = pre->next;
            }
            current = current->next;
        }

        return head;
    }
};


int main() {
    return 0;
}
