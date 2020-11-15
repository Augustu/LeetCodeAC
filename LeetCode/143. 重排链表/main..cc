#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;

        // split linked list into two parts
        ListNode* second = head;
        ListNode* tmp = head->next;
        while (tmp && tmp->next) {
            second = second->next;
            tmp = tmp->next->next;
        }
        tmp = second->next;
        second->next = nullptr;
        second = tmp;


        // reverse the second linked list
        second = reverse(second);

        while (head && head->next) {
            ListNode* post = head->next;
            if (second) {
                //// heap use after free fatal
                // head->next = second;
                // head->next->next = post;
                // second = second->next;
                // head = post;
                ListNode* tmp = second->next;
                head->next = second;
                second->next = post;
                second = tmp;
                head = post;
            } else {
                break;
            }
        }

        if (second) {
            head->next = second;
        }
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* post = curr->next;
            curr->next = prev;
            prev = curr;
            curr = post;
        }
        return prev;
    }

    void printList(ListNode *head) {
        while (head) {
            cout << head->next << " ";
            head = head->next;
        }
        cout << endl;
    }
};


// TODO using stack


int main() {
    return 0;
}
