#include "tree"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return treeDepth(root);
    }

    int treeDepth(TreeNode* root) {
        if (root != nullptr) {
            int left = treeDepth(root->left);
            int right = treeDepth(root->right);
            return left > right ? left+1 : right+1;
        }
        return 0;
    }
};


int main() {
    return 0;
}
