#include <iostream>

#include <map>
#include <vector>
#include "linkedlist"

using namespace std;


/* do not consider duplication :(
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<int, Node*> dict;

        Node* tmp = head;
        while (tmp) {
            dict.insert(pair<int, Node*>(tmp->val, new Node(tmp->val)));
            tmp = tmp->next;
        }

        tmp = head;
        while (tmp) {
            map<int, Node*>::iterator current = dict.find(tmp->val);
            
            if (tmp->next) {
                map<int, Node*>::iterator next = dict.find(tmp->next->val);
                current->second->next = next->second;
            }

            if (tmp->random) {
                map<int, Node*>::iterator random = dict.find(tmp->random->val);
                current->second->random = random->second;
            }

            tmp = tmp->next;
        }

        return dict.find(head->val)->second;
    }
};
*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> dict;

        Node* tmp = head;
        while (tmp) {
            dict.insert(pair<Node*, Node*>(tmp, new Node(tmp->val)));
            tmp = tmp->next;
        }
        dict.insert(pair<Node*, Node*>(nullptr, nullptr));

        tmp = head;
        while (tmp) {
            map<Node*, Node*>::iterator current = dict.find(tmp);
            map<Node*, Node*>::iterator next = dict.find(tmp->next);
            current->second->next = next->second;

            map<Node*, Node*>::iterator random = dict.find(tmp->random);
            current->second->random = random->second;

            tmp = tmp->next;
        }

        return dict.find(head)->second;
    }
};

// TODO
// https://leetcode-cn.com/submissions/detail/123403154/
// 将a->b->c链表拷贝成a->a'->b->b'->c->c'
// 设置指针
// 拆分出新链表

int main() {
    return 0;
}
