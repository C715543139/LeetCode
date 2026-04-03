#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> res;

    vector<int> inorderTraversal(TreeNode *root) {
        inOrder(root);
        return res;
    }

    void inOrder(TreeNode *root) {
        if (!root) {
            return;
        }

        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<pair<TreeNode *, int>> s;
        s.emplace(root, 0);

        while (!s.empty()) {
            TreeNode *node = s.top().first;
            int state = s.top().second;
            s.pop();

            if (node) {
                if (state == 0) {
                    s.emplace(node->right, 0);
                    s.emplace(node, 1);
                    s.emplace(node->left, 0);
                } else {
                    res.push_back(node->val);
                }
            }
        }
        return res;
    }
};

class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();

            if (node) {
                if (!node->left && !node->right) {
                    res.push_back(node->val);
                } else {
                    s.push(node->right);
                    s.push(node);
                    s.push(node->left);
                    node->right = nullptr;
                    node->left = nullptr;
                }
            }
        }
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    root = new TreeNode(2, root, nullptr);
    root = new TreeNode(1, nullptr, root);
    auto i = Solution2().inorderTraversal(root);
    return 0;
}
