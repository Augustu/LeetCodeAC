#include <iostream>
#include <vector>

#include "linkedlist"

using namespace std;


class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        head = reverseList(head);
        while (head) {
            result.emplace_back(head->val);
            head = head->next;
        }
        return result;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};


int main() {
    ListNode* test_1 = makeLinkedList(1,3,2);

    vector<int> result;
    Solution s;
    result = s.reversePrint(test_1);
    for (auto r : result) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}


