#include <iostream>

#include "linkedlist"

using namespace std;

typedef LinkNode<int> ListNode;

// copy from 面试题 02.02. 返回倒数第 k 个节点
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* first = head;
        while (k--) {
            first = first->next;
        }

        while (first) {
            first = first->next;
            head = head->next;
        }

        return head->val;
    }
};


int main() {
    ListNode* test_1 = makeLinkedList(1,2,3,4,5);

    int result;
    Solution s;
    result = s.kthToLast(test_1, 2);
    cout << result << endl;

    return 0;
}

