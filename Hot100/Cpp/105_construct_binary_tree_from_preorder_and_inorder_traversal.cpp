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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, inorder, 0, inorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int is, int ie) {
        // 根节点遍历完成
        if (preorder.empty()) return nullptr;
        // 无节点可构造
        if (is > ie) return nullptr;

        // 根节点
        int val = preorder.front();
        preorder.erase(preorder.begin());
        // 寻找根节点在中序遍历中的位置，确定左右子树
        int idx = is;
        while (idx <= ie && inorder[idx] != val) idx++;
        return new TreeNode(val, build(preorder, inorder, is, idx - 1), build(preorder, inorder, idx + 1, ie));
    }
};

int main() {
    return 0;
}
