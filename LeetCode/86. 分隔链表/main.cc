#include <iostream>

#include "linkedlist"

using namespace std;


/* this sort the result, but clearly not the answer :(
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;

        ListNode* sentinel = new ListNode(-1, head);
        while (head) {
            if (head->val >= x) {
                break;
            }
            head = head->next;
        }

        if (!head) return sentinel->next;

        // found x at head, move little val before x
        ListNode* del_pre = head;
        head = head->next;
        while (head) {
            if (head->val < x) {
                ListNode* post = head->next;
                ListNode* insert_pre = sentinel;
                ListNode* shadow_head = sentinel->next;
                while (shadow_head) {
                    // found position to insert
                    if (shadow_head->val > head->val) {
                        // insert the node
                        head->next = shadow_head;
                        insert_pre->next = head;
                        break;
                    }

                    insert_pre = insert_pre->next;
                    shadow_head = shadow_head->next;
                }

                // del the node
                del_pre->next = post;
                head = post;
                continue;
            }

            del_pre = del_pre->next;
            head = head->next;
        }

        return sentinel->next;
    }
};
*/


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;

        ListNode* sentinel = new ListNode(-1);
        sentinel->next = head;

        ListNode* prev = sentinel;
        ListNode* anchor = head;
        while (anchor) {
            if (anchor->val >= x) {
                break;
            }
            prev = prev->next;
            anchor = anchor->next;
        }

        if (!anchor) {
            return head;
        }

        ListNode* pre_rest = anchor;
        ListNode* rest = anchor->next;
        while (rest) {
            if (rest->val < x) {
                // del rest in linked list, do not move pre_rest
                pre_rest->next = rest->next;

                // insert rest between prev and anchor
                ListNode* post = rest->next;
                prev->next = rest;
                rest->next = anchor;
                prev = prev->next;
                rest = post;
            } else {
                pre_rest = pre_rest->next;
                rest = rest->next;
            }
        }

        return sentinel->next;
    }
};


int main() {
    ListNode* test_1 = makeLinkedList(1,4,3,2,5,2);
    ListNode* test_2 = makeLinkedList(3,1);
    ListNode* test_3 = makeLinkedList(2,3,1);

    ListNode* result;
    Solution s;
    result = s.partition(test_1, 3);
    printLinkedList(result);
    // result = s.partition(test_1, 2);
    // printLinkedList(result);
    // result = s.partition(test_1, 5);
    // printLinkedList(result);
    // result = s.partition(test_2, 2);
    // printLinkedList(result);
    // result = s.partition(test_3, 3);
    // printLinkedList(result);

    return 0;
}
