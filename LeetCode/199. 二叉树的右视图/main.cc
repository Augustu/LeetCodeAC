#include "tree"

#include <vector>
#include <queue>


using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // TODO finish this
        if (!root) return vector<int>();

        int level = 0;
        int nextLevel = 0;
        int currentRest = 1;
        vector<int> result;

        queue<TreeNode*> treeNodeQueue;
        treeNodeQueue.push(root);

        while (!treeNodeQueue.empty()) {
            TreeNode* node = treeNodeQueue.front();
            if (currentRest == 1) {
                result.emplace_back(node->val);
            }

            if (!node->left) {
                treeNodeQueue.push(node->left);
            }
            if (!node->right) {
                treeNodeQueue.push(node->right);
            }
        }

        return result;
    }
};


int main() {
    return 0;
}
