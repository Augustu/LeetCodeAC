#include "tree"

#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();

        queue<TreeNode*> treeNodeQueue;
        treeNodeQueue.push(root);
        int nextLevel = 0;
        int currentRest = 1;
        int level = 0;

        vector<vector<int>> result;
        result.emplace_back(vector<int>());

        while (!treeNodeQueue.empty()) {
            TreeNode* node = treeNodeQueue.front();
            result[level].emplace_back(node->val);

            if (node->left) {
                treeNodeQueue.push(node->left);
                ++nextLevel;
            }
            if (node->right) {
                treeNodeQueue.push(node->right);
                ++nextLevel;
            }

            treeNodeQueue.pop();
            --currentRest;

            if (currentRest == 0 && nextLevel != 0) {
                result.emplace_back(vector<int>());
                ++level;
                currentRest = nextLevel;
                nextLevel = 0;
            }
        }

        return result;
    }
};


int main() {
    return 0;
}
