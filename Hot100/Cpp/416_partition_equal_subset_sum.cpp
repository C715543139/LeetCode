#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    map<pair<int, int>, bool> mp;

    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (const int num: nums) sum += num;

        if (sum % 2 != 0) {
            return false;
        }

        sum /= 2;
        return f(nums, 1, sum) || f(nums, 1, sum - nums[0]);
    }

    bool f(vector<int> &nums, int idx, int sum) {
        if (mp.find(pair{idx, sum}) != mp.end()) {
            return mp[pair{idx, sum}];
        }
        if (sum == 0) {
            return true;
        }
        if (idx == nums.size() || sum < 0) {
            return false;
        }
        bool res = f(nums, idx + 1, sum - nums[idx]) || f(nums, idx + 1, sum);
        mp[pair{idx, sum}] = res;
        return res;
    }
};

class Solution2 {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (const int num: nums) sum += num;

        if (sum % 2 != 0) {
            return false;
        }

        sum /= 2;
        vector v(nums.size(), vector(sum + 1, false));
        for (int i = 0; i < nums.size(); ++i) {
            v[i][0] = true;
        }
        if (nums[0] <= sum) {
            for (int i = 0; i < nums.size(); ++i) {
                v[i][nums[0]] = true;
            }
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (nums[i] <= j) {
                    v[i][j] = v[i - 1][j] || v[i - 1][j - nums[i]];
                }
            }
        }
        return v[nums.size() - 1][sum];
    }
};

class Solution3 {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (const int num: nums) sum += num;

        if (sum % 2 != 0) {
            return false;
        }

        sum /= 2;
        vector v(sum + 1, false);
        v[0] = true;

        if (nums[0] <= sum) {
            v[nums[0]] = true;
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = sum; j > 0; --j) { // 倒序，当使用 j - nums[i] 时还未更新，是 i - 1 时的结果
                if (nums[i] <= j) {
                    v[j] = v[j] || v[j - nums[i]];
                }
            }
        }
        return v[sum];
    }
};

int main() {
    vector v{1, 2, 5};
    cout << Solution3().canPartition(v) << endl;
    return 0;
}
