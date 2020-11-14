#include <iostream>

#include "linkedlist"

using namespace std;


/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        headA = new ListNode(-1, headA);
        headB = new ListNode(-1, headB);

        while (headA) {
            ListNode* tmpB = headB;
            while (tmpB) {
                if (headA->next == tmpB->next && headA->next != nullptr) {
                    cout << "Intersected at '" << headA->next->val << "'" << endl;
                    return tmpB->next;
                }
                tmpB = tmpB->next;
            }

            headA = headA->next;
        }

        return nullptr;
    }
};
*/

// https://leetcode-cn.com/problems/intersection-of-two-linked-lists-lcci/solution/ji-he-shuang-zhi-zhen-deng-3chong-jie-jue-fang-s-3/
// method 2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int dif=Listlen(headA)-Listlen(headB);
        if(dif>=0) 
            headA=moveNode(headA,dif);
        else
            headB=moveNode(headB,-dif);
        while(headA&&headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
    ListNode *moveNode(ListNode *L, int s) {
        while(s){
            s--;
            L=L->next;
        }
        return L;
    }
    int Listlen(ListNode *head) {
        int i=0;
        while(head){
            head=head->next;
            i++;
        }
        return i;
    }
};



int main() {
    return 0;
}
