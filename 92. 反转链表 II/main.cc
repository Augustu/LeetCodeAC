#include <iostream>

#include "linkedlist"

using namespace std;


typedef LinkNode<int> ListNode;


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // TODO solve this
    }
};


int main() {
    ListNode* test_1 = makeLinkedList(1,2,3,4,5);

    ListNode* result;
    Solution s;
    result = s.reverseBetween(test_1, 2, 4);
    printLinkedList(result);

    return 0;
}
