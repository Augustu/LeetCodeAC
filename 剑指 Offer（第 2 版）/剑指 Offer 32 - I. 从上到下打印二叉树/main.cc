#include "tree"
#include <iostream>

#include <vector>
#include <deque>

using namespace std;


class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (!root) return vector<int>();

        vector<int> result;

        deque<TreeNode*> treeNodeDeque;
        treeNodeDeque.push_back(root);

        while (treeNodeDeque.size()) {
            TreeNode *node = treeNodeDeque.front();
            treeNodeDeque.pop_front();

            result.emplace_back(node->val);

            if (node->left) {
                treeNodeDeque.emplace_back(node->left);
            }
            if (node->right) {
                treeNodeDeque.emplace_back(node->right);
            }

        }

        return result;
    }
};


int main() {
    return 0;
}
