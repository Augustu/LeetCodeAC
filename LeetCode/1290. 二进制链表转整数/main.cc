#include <iostream>

#include "linkedlist"

using namespace std;


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head) {
            result *= 2;
            result += head->val;
            head = head->next;
        }
        return result;
    }
};


int main() {
    return 0;
}
