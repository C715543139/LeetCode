#include <iostream>
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

    vector<int> rightSideView(TreeNode *root) {
        preOrder(root, 0);
        return res;
    }

    void preOrder(TreeNode *root, int depth) {
        if (root == nullptr) return;
        if (res.size() < depth + 1) res.resize(depth + 1);
        res[depth] = root->val;
        preOrder(root->left, depth + 1);
        preOrder(root->right, depth + 1);
    }
};

int main() {
    auto root = new TreeNode(1, new TreeNode(2, new TreeNode(4, new TreeNode(5), nullptr), nullptr), new TreeNode(3));
    Solution().rightSideView(root);
    return 0;
}
