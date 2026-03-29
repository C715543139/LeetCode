#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int missing = 1;
        for (auto num: nums) {
            if (num == missing) {
                missing++;
            }
        }
        return missing;
    }
};

class Solution2 {
public:
    int firstMissingPositive(vector<int> &nums) {
        vector bucket(100002, false);
        for (auto num: nums) {
            if (num > 0 && num < 100002) {
                bucket[num] = true;
            }
        }
        for (int i = 1; i <= 100001; i++) {
            if (!bucket[i]) {
                return i;
            }
        }
        return 1;
    }
};

class Solution3 {
public:
    int firstMissingPositive(vector<int> &nums) {
        int size = nums.size();
        for (auto &num: nums) {
            if (num <= 0) {
                num = 100003;
            }
        }
        for (auto num: nums) {
            num = abs(num);
            if (num <= size) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return size + 1;
    }
};

int main() {
    Solution s;
    vector nums{3, 4, -1, 1};
    cout << s.firstMissingPositive(nums) << endl;
    return 0;
}
