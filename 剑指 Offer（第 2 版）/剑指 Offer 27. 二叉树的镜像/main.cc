#include <iostream>

#include "tree"

using namespace std;

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        mirror(root);
        return root;
    }

    void mirror(TreeNode* root) {
        if (!root) return;

        swap(root->left, root->right);

        mirror(root->left);
        mirror(root->right);
    }
};

int main() {
    return 0;
}