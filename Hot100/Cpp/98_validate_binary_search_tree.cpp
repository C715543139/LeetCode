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
    long long last = LONG_LONG_MIN;
    bool flag = true;

    bool isValidBST(TreeNode* root) {
        inOrder(root);
        return flag;
    }

    void inOrder(TreeNode* root) {
        if (!root || !flag) return;
        inOrder(root->left);
        if (root->val <= last) {
            flag = false;
            return;
        }
        last = root->val;
        inOrder(root->right);
    }
};

int main() {
    auto root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    cout << Solution().isValidBST(root) << endl;
    return 0;
}