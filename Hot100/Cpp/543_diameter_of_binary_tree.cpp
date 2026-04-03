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
    int longest = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        if (!root->left && !root->right) return 0;
        depth(root);
        return longest;
    }

    int depth(TreeNode *root) {
        if (!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        longest = max(left + right, longest);
        return max(left, right) + 1;
    }
};

int main() {
    auto root = new TreeNode(1, nullptr, new TreeNode(2));
    cout << Solution().diameterOfBinaryTree(root);
    return 0;
}
