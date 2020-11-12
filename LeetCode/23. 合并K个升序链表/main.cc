#include <iostream>

#include <vector>
#include "linkedlist"
#include <list>

using namespace std;

typedef LinkNode<int> ListNode;


void PrintLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


/* solution one
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() < 1) return nullptr;

        ListNode* back = lists.back();
        lists.pop_back();
        return mergeListsRecurse(lists, back);
    }

    ListNode* mergeListsRecurse(vector<ListNode*>& lists, ListNode* back) {
        if (lists.size() == 0) return back;
        if (lists.size() == 1) return mergeTwoLists(lists.at(0), back);

        ListNode* b = lists.back();
        lists.pop_back();
        return mergeListsRecurse(lists, mergeTwoLists(back, b));

    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* head = new ListNode(0);
        ListNode* current = head;
        while (l1 != nullptr && l2 != nullptr) {
            while (l1 != nullptr && l2 != nullptr
                   && l1->val <= l2->val) {
                current->next = l1;
                current = current->next;
                l1 = l1->next;
            }
            while (l1 != nullptr && l2 != nullptr
                   && l1->val > l2->val) {
                current->next = l2;
                current = current->next;
                l2 = l2->next;
            }
        }

        if (l1 != nullptr) current->next = l1;
        if (l2 != nullptr) current->next = l2;

        return head->next;
    }
};
*/


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        return merge(lists, 0, lists.size()-1);
    }

    ListNode* merge(vector<ListNode*>& lists, int start, int end) {
        if (start == end) return lists.at(start);
        int mid = (start + end) / 2;
        ListNode* l1 = merge(lists, start, mid);
        ListNode* l2 = merge(lists, mid+1, end);
        return merge(l1, l2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};



int main() {
    vector<ListNode*> test_1 = vector<ListNode*>{ makeLinkedList(1,4,5),
                                                  makeLinkedList(1,3,4),
                                                  makeLinkedList(2,6) };
    vector<ListNode*> test_2 = vector<ListNode*>{};
    vector<ListNode*> test_3 = vector<ListNode*>{ nullptr };
    vector<ListNode*> test_4 = vector<ListNode*>{ nullptr, makeLinkedList(1) };

    ListNode* result;
    Solution s;
    result = s.mergeKLists(test_1);
    PrintLinkedList(result);
    result = s.mergeKLists(test_2);
    PrintLinkedList(result);
    result = s.mergeKLists(test_3);
    PrintLinkedList(result);
    result = s.mergeKLists(test_4);
    PrintLinkedList(result);

    return 0;
}

