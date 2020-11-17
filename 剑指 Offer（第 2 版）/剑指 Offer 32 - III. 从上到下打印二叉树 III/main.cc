#include "tree"

#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();

        vector<vector<int>> result;
        result.emplace_back(vector<int>());

        int level = 0;
        int nextLevel = 0;
        int currentRest = 1;

        queue<TreeNode*> treeNodeTree;
        treeNodeTree.push(root);

        while (!treeNodeTree.empty()) {
            TreeNode* node = treeNodeTree.front();
            result[level].emplace_back(node->val);

            if (node->left) {
                treeNodeTree.push(node->left);
                ++nextLevel;
            }
            if (node->right) {
                treeNodeTree.push(node->right);
                ++nextLevel;
            }

            treeNodeTree.pop();
            --currentRest;

            if (currentRest == 0) {
                if (level % 2) {
                    // reverse this level
                    reverse(result[level]);
                }
            }

            if (currentRest == 0 && nextLevel != 0) {
                result.emplace_back(vector<int>());
                ++level;

                currentRest = nextLevel;
                nextLevel = 0;
            }
        }

        return result;
    }

    void reverse(vector<int>& vec) {
        int need = vec.size() / 2;
        for (int i=0; i<need; ++i) {
            swap(vec[i], vec[vec.size()-i-1]);
        }
    }
};


int main() {
    return 0;
}
