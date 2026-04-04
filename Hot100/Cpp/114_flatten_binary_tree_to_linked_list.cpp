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
    void flatten(TreeNode *root) {
        preOrder(root);
    }

    TreeNode *preOrder(TreeNode *root) {
        if (!root) return nullptr;
        TreeNode *left = preOrder(root->left);
        TreeNode *right = preOrder(root->right);
        root->left = nullptr;
        root->right = left;

        auto temp = root;
        while (temp->right) temp = temp->right;
        temp->right = right;
        return root;
    }
};

class Solution2 {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        auto left = root->left, right = root->right;
        root->left = nullptr;
        root->right = left;

        auto temp = root;
        while (temp->right) temp = temp->right;
        temp->right = right;
    }
};

class Solution3 {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) return;

        flatten(root->right);
        if (root->left != nullptr) {
            flatten(root->left);
            auto temp = root->left;
            while (temp->right != nullptr) {
                temp = temp->right;
            }
            temp->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};

int main() {
    return 0;
}
