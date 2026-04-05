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
    int maxSum = INT_MIN;

    int maxPathSum(TreeNode* root) {
        auto hair = new TreeNode(0, root, nullptr);
        postOrder(hair);
        return maxSum;
    }

    int postOrder(TreeNode* root) {
        if (!root) return INT_MIN;
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        maxSum = max(max(left, right), maxSum);
        if (left == INT_MIN) left = 0;
        if (right == INT_MIN) right = 0;
        maxSum = max(maxSum, left + right + root->val);
        return max(max(left + root->val, right + root->val), root->val);
    }
};

int main() {
    auto root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << Solution().maxPathSum(root) << endl;
    return 0;
}