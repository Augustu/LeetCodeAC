#include <iostream>

#include "linkedlist"
#include <vector>

using namespace std;


// TODO fix me :(
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        if (!root) return vector<ListNode*>(k, nullptr);

        ListNode* tmp = root;
        int length = 0;
        while (tmp) {
            length++;
            tmp = tmp->next;
        }

        int interval = length / k;
        int first = 0;
        if (interval != 0) {
            first = interval + length%k;
        } else {
            interval = 1;
            first = 1;
        }
        vector<ListNode*> result;

        result.emplace_back(root);
        tmp = root;
        first--;
        while (first--) {
            tmp = tmp->next;
        }
        ListNode* second = tmp->next;
        tmp->next = nullptr;

        k--;
        while (k--) {
            if (!second) {
                result.emplace_back(nullptr);
                continue;
            }

            result.emplace_back(second);
            for (int i=1; i<interval; ++i) {
                second = second->next;
            }
            ListNode* post = second->next;
            second->next = nullptr;
            second = post;
        }

        return result;
    }
};


int main() {
    return 0;
}
