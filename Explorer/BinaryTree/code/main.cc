#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/**
 * https://en.wikipedia.org/wiki/Tree_traversal#Post-order_(LRN)
 * https://en.wikipedia.org/wiki/Breadth-first_search
*/

class Solution
{
private:

public:
    Solution() {}

    /* Recursion */
    // vector<int> PreOrderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     vector<int> left;
    //     vector<int> right;

    //     if (root->left) {
    //         left = PreOrderTraversal(root->left);
    //     }
    //     if (root->right) {
    //         right = PreOrderTraversal(root->right);
    //     }

    //     result.push_back(root->val);
    //     result.insert(result.end(), left.begin(), left.end());
    //     result.insert(result.end(), right.begin(), right.end());
    //     return result;
    // }

    /* Iteration */
    vector<int> PreOrderTraversal(TreeNode* root) {

        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        stack<TreeNode*> tmp;

        result.emplace_back(root->val);
        while(root) {
            if (root->right) {
                tmp.push(root->right);
            }
            if (root->left) {
                result.emplace_back(root->left->val);
                root = root->left;
            } else {
                if (tmp.empty()) {
                    break;
                }
                TreeNode* right = tmp.top();
                tmp.pop();
                result.emplace_back(right->val);
                root = right;
            }
        }

        return result;
    }


    /* InorderTraversal */

    /* Recursion */
    // vector<int> InorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     vector<int> left;
    //     vector<int> right;

    //     if (root->left) {
    //         left = InorderTraversal(root->left);
    //     }

    //     if (root->right) {
    //         right = InorderTraversal(root->right);
    //     }

    //     result.insert(result.end(), left.begin(), left.end());
    //     result.emplace_back(root->val);
    //     result.insert(result.end(), right.begin(), right.end());

    //     return result;
    // }

    /* Iteration */
    vector<int> InorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }

        stack<TreeNode*> tmp;

        while (root || !tmp.empty()) {
            while (root) {
                tmp.push(root);
                root = root->left;
            }

            root = tmp.top();
            tmp.pop();
            result.emplace_back(root->val);

            root = root->right;
        }

        return result;
    }


    /* PostorderTraversal */

    /* Recursion */
    // vector<int> PostorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     vector<int> left;
    //     vector<int> right;

    //     if (root->left) {
    //         left = PostorderTraversal(root->left);
    //     }
    //     if (root->right) {
    //         right = PostorderTraversal(root->right);
    //     }

    //     result.insert(result.end(), left.begin(), left.end());
    //     result.insert(result.end(), right.begin(), right.end());
    //     result.emplace_back(root->val);

    //     return result;
    // }

    /* Iteration */
    vector<int> PostorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }

        stack<TreeNode*> s;
        TreeNode* last_node_visited = nullptr;

        while (!s.empty() || root) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                TreeNode* peek_node = s.top();
                if (peek_node->right && last_node_visited != peek_node->right) {
                    root = peek_node->right;
                } else {
                    result.emplace_back(peek_node->val);
                    last_node_visited = s.top();
                    s.pop();
                }
            }
        }

        return result;
    }


    /* Level Order append nullptr, when two nullptr appends together, it's time to end */
    // vector<vector<int>> LevelOrderTraversal(TreeNode* root) {
    //     vector<vector<int>> result;
    //     if (!root) {
    //         return result;
    //     }

    //     queue<TreeNode*> q;
    //     q.emplace(root);
    //     q.emplace(nullptr);

    //     // int l = 0;
    //     vector<int>* level = new vector<int>();

    //     while (!q.empty()) {
    //         TreeNode* node = q.front();
    //         q.pop();

    //         if (!node) {
    //             q.emplace(nullptr);
    //             result.emplace_back(*level);
    //             // l++;
    //             // cout << endl;
    //             if (!q.front()) {
    //                 break;
    //             }
    //             level = new vector<int>();
    //             continue;
    //         }

    //         level->emplace_back(node->val);
    //         // cout << node->val << " ";

    //         if (node->left) {
    //             q.emplace(node->left);
    //         }
    //         if (node->right) {
    //             q.emplace(node->right);
    //         }
    //     }

    //     return result;
    // }

    vector<vector<int>> LevelOrderTraversal(TreeNode* root) {
        if (nullptr == root)
            return vector<vector<int>>();

        queue<TreeNode*> que;
        que.emplace(root);

        vector<vector<int>> result;

        while (!que.empty()) {
            int number = que.size();
            vector<int> tmp;

            for (int i=0; i<number; ++i) {
                TreeNode* node = que.front();
                que.pop();

                tmp.emplace_back(node->val);

                if (node->left != nullptr)
                    que.emplace(node->left);
                if (node->right != nullptr)
                    que.emplace(node->right);
            }

            result.emplace_back(tmp);
        }

        return result;
    }

};



int main() {
    // TreeNode* root = new TreeNode(1);
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(3);

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    TreeNode* right = root->right;
    right->left = new TreeNode(15);
    right->right = new TreeNode(7);

    Solution s;
    // vector<int> result = s.PreOrderTraversal(root);
    // vector<int> result = s.InorderTraversal(root);
    // vector<int> result = s.PostorderTraversal(root);

    // for (auto r : result) {
    //     cout << r << " ";
    // }
    // cout << endl;

    vector<vector<int>> result = s.LevelOrderTraversal(root);
    for (vector<int> vec : result) {
        for (int v : vec) {
            cout << v << " ";
        }
        cout << endl;
    }

    free(right->right);
    free(right->left);
    free(right);
    free(root->left);
    free(root);

    return 0;
}