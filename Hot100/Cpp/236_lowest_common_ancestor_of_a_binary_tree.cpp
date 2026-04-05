#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    bool f1 = false, f2 = false;
    TreeNode *tn1 = nullptr, *tn2 = nullptr, *res = nullptr;

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        tn1 = p;
        tn2 = q;
        postOrder(root);
        return res;
    }

    void postOrder(TreeNode *root) {
        if (!root || res != nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        f1 |= root->val == tn1->val;
        f2 |= root->val == tn2->val;
        if (!res && f1 && f2 && isSubTree(root, tn1) && isSubTree(root, tn2)) {
            res = root;
        }
    }

    bool isSubTree(TreeNode *root, TreeNode *child) {
        if (!root) return false;
        if (root == child) return true;
        return isSubTree(root->left, child) || isSubTree(root->right, child);
    }
};

int main() {
    TreeNode *p, *q;
    auto root = new TreeNode(3,
                             p = new TreeNode(5,
                                          new TreeNode(6),
                                          q = new TreeNode(4)),
                             new TreeNode(1)
    );
    root = Solution().lowestCommonAncestor(root, p, q);
    return 0;
}
