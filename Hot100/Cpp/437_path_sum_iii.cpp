#include <iostream>
#include <unordered_map>
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
    unordered_map<long long, int> mp;
    int target = 0, sum = 0;

    int pathSum(TreeNode *root, int targetSum) {
        target = targetSum;
        preOrder(root);
        return sum;
    }

    void preOrder(TreeNode *root) {
        if (!root) return;
        if (root->val == target) sum++;

        auto i = mp.find(root->val);
        if (i != mp.end()) {
            sum += i->second;
        }
        unordered_map<long long, int> newMap;
        for (const auto &it: mp) {
            newMap[it.first - root->val] = it.second;
        }
        if (newMap.find(target - root->val) != newMap.end()) {
            newMap[target - root->val] += 1;
        } else {
            newMap[target - root->val] = 1;
        }

        auto oldMap = std::move(mp);
        mp = std::move(newMap);
        preOrder(root->left);
        preOrder(root->right);
        mp = std::move(oldMap);
    }
};

class Solution2 {
public:
    int pathSum(TreeNode *root, long long targetSum) {
        if (!root) return 0;
        int sum = preOrder(root, targetSum);
        sum += pathSum(root->left, targetSum);
        sum += pathSum(root->right, targetSum);
        return sum;
    }

    int preOrder(TreeNode *root, long long targetSum) {
        if (!root) return 0;
        int sum = 0;
        if (root->val == targetSum) sum++;
        sum += preOrder(root->left, targetSum - root->val);
        sum += preOrder(root->right, targetSum - root->val);
        return sum;
    }
};

class Solution3 {
public:
    unordered_map<long long, int> prefix;
    int sum = 0, target = 0;

    int pathSum(TreeNode *root, int targetSum) {
        target = targetSum;
        prefix[0] = 1;
        preOrder(root, 0);
        return sum;
    }

    void preOrder(TreeNode *root, long long cur) {
        if (!root) return;
        cur += root->val;
        if (prefix.count(cur - target)) {
            sum += prefix[cur - target];
        }
        prefix[cur]++;
        preOrder(root->left, cur);
        preOrder(root->right, cur);
        prefix[cur]--;
    }
};

int main() {
    auto root = new TreeNode(10,
                             new TreeNode(5,
                                          new TreeNode(3,
                                                       new TreeNode(3),
                                                       new TreeNode(-2)),
                                          new TreeNode(2,
                                                       nullptr,
                                                       new TreeNode(1))),
                             new TreeNode(-3,
                                          nullptr,
                                          new TreeNode(11)));
    cout << Solution().pathSum(root, 8);
    return 0;
}
