#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxLen = 1;

    int lengthOfLIS(vector<int> &nums) {
        int idx = 0;
        while (idx < nums.size() - 1 && nums[idx] > nums[idx + 1]) idx++;
        vector<int> sq;
        f(nums, idx, sq);
        return maxLen;
    }

    void f(vector<int> &nums, int idx, vector<int> &sq) {
        if (idx == nums.size()) {
            maxLen = max(maxLen, (int)sq.size());
            return;
        }

        int num = nums[idx];
        if (sq.empty() || num > sq.back()) {
            sq.push_back(num);
        } else if (num < sq.back() && num > sq.front()) {
            vector sqd = sq;
            while (num <= sqd.back()) sqd.pop_back();
            sqd.push_back(num);
            f(nums, idx + 1, sqd);
        } else if (num < sq.front()) {
            vector nsq{num};
            f(nums, idx + 1, nsq);
        }
        f(nums, idx + 1, sq);
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int> &nums) {
        int res = 1;
        vector maxLen(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            for (int j = 0; j < i; j++) { // 包含当前数字的最长序列 = max(比当前数字小的结尾的序列长度 + 1)
                if (nums[j] < num) {
                    maxLen[i] = max(maxLen[i], maxLen[j] + 1);
                }
            }
            res = max(res, maxLen[i]);
        }
        return res;
    }
};

int main() {
    vector v{11, 12, 13, 14, 15, 6, 7, 8, 101, 18};
    cout << Solution().lengthOfLIS(v) << endl;
    return 0;
}
