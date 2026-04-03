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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return construct(nums, 0, nums.size() - 1);
    }

    TreeNode *construct(vector<int> &nums, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = construct(nums, start, mid - 1);
        root->right = construct(nums, mid + 1, end);
        return root;
    }
};

int main() {
    auto v = vector{0, 1, 2, 3, 4, 5};
    auto root = Solution().sortedArrayToBST(v);
    return 0;
}
