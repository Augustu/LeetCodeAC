#include <iostream>

#include "linkedlist"

using namespace std;


typedef LinkNode<int> ListNode;


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        if (head->next->next == nullptr) {
            ListNode* post = head->next;
            post->next = head;
            head->next = nullptr;
            return post;
        }

        // TODO beautify this loop
        ListNode* pre = head;
        ListNode* middle = head->next;
        ListNode* post = head->next->next;
        pre->next = nullptr;
        while (post != nullptr) {
            middle->next = pre;
            pre = middle;
            middle = post;
            post = post->next;
        }
        middle->next = pre;
        return middle;
    }
};


int main() {
    LinkNode<int> *test_1 = makeLinkedList(1,2,3,4,5);
    // LinkNode<int> *test_2 = makeLinkedList( 1, 3, 4);

    Solution s;

    LinkNode<int> *head = s.reverseList(test_1);
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
