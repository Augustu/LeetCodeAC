#include "tree"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return depth(root);
    }

    int depth(TreeNode* root) {
        if (!root) return 0;

        int left = depth(root->left);
        int right = depth(root->right);

        return left > right ? left + 1 : right + 1;
    }
};

int main() {
    return 0;
}