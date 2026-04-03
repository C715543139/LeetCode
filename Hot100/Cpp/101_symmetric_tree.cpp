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
    vector<int> left, right;

    bool isSymmetric(TreeNode *root) {
        return isSym(root->left, root->right);
    }

    bool isSym(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        if (left->val != right->val) return false;
        return isSym(left->left, right->right) && isSym(left->right, right->left);
    }
};

int main() {
    auto root = new TreeNode(1, new TreeNode(2, new TreeNode(2), nullptr), new TreeNode(2, new TreeNode(2), nullptr));
    cout << Solution().isSymmetric(root);
    return 0;
}
