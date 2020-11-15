#include <iostream>

#include "linkedlist"
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> nums;

        ListNode* tmp = head;
        while (tmp) {
            nums.emplace_back(tmp->val);
            tmp = tmp->next;
        }

        sort(nums.begin(), nums.end(), [](int a, int b){ return a>b; });

        tmp = head;
        int i = 0;
        while (tmp) {
            tmp->val = nums[i];
            i++;
            tmp = tmp->next;
        }

        return head;
    }
};


// TODO quick sort practice


int main() {
    return 0;
}
