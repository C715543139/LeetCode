#include <iostream>
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
    int count;
    int kth;

    int kthSmallest(TreeNode *root, int k) {
        count = k;
        inOrder(root);
        return kth;
    }

    void inOrder(TreeNode *root) {
        if (!root) return;
        inOrder(root->left);
        count--;
        if (count == 0) {
            kth = root->val;
            return;
        }
        inOrder(root->right);
    }
};

int main() {
    return 0;
}
