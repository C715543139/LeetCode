#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        queue<pair<TreeNode *, int>> q;

        q.emplace(root, 0);
        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            auto node = it.first;
            int depth = it.second;
            if (node) {
                if (res.size() < depth + 1) {
                    res.emplace_back();
                }
                res[depth].push_back(node->val);
                q.emplace(node->left, depth + 1);
                q.emplace(node->right, depth + 1);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> res;

    vector<vector<int>> levelOrder(TreeNode *root) {
        f(root, 0);
        return res;
    }

    void f(TreeNode *root, int depth) {
        if (root == nullptr) return;
        if (res.size() < depth + 1) res.emplace_back();
        res[depth].push_back(root->val);
        f(root->left, depth + 1);
        f(root->right, depth + 1);
    }
};

int main() {
    return 0;
}
