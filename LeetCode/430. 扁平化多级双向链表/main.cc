#include <iostream>

#include <stack>
#include "linkedlist"

using namespace std;


class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        Node* node = head;

        while (node->next || node->child) {
            if (node->child) {
                Node* post = node->next;
                node->next = node->child;

                Node* ch = node->child;
                ch->prev = node;
                while (ch->next) {
                    ch = ch->next;
                }
                ch->next = post;
                if (post) {
                    post->prev = ch;
                }
            }

            node->child = nullptr;
            node = node->next;
        }

        return head;
    }
};


int main() {
    return 0;
}