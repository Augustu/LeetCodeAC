#include <iostream>

#include <tree>

using namespace std;


// ref: https://www.jianshu.com/p/778eceb7e229
class Solution {
public:
    int rob(TreeNode* root) {
        return SolutionTree(root)->val;
    }

    TreeNode* SolutionTree(TreeNode* root) {
        if (root == nullptr) {
            TreeNode* treeNode = new TreeNode(0);
            return SolutionTree(treeNode);
        }

        if (root->left == nullptr && root->right == nullptr) {
            root->left = new TreeNode(0);
            root->right = new TreeNode(0);
            return root;
        }

        root->left = SolutionTree(root->left);
        root->right = SolutionTree(root->right);

        // Q: figure out why this root->right->left etc. can work
        // A: if pointer is nullptr, created a zero node to replace nullptr
        root->val = max(root->left->val + root->right->val,
                        root->val + root->left->left->val + root->left->right->val
                        + root->right->left->val + root->right->right->val);

        return root;
    }
};


int main() {
    return 0;
}
