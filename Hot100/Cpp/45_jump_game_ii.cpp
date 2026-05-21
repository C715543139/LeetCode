#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        size_t size = nums.size();
        if (size == 1) {
            return 0;
        }
        vector minStep(size, INT_MAX);
        minStep[0] = 0;
        for (int i = 0; i < size; i++) {
            if (i + nums[i] >= size - 1) {
                return minStep[i] + 1;
            }
            for (int j = 1; j <= nums[i]; j++) {
                minStep[i + j] = min(minStep[i + j], minStep[i] + 1);
            }
        }
        return 0;
    }
};

class Solution2 {
public:
    int jump(vector<int> &nums) {
        size_t size = nums.size();
        if (size == 1) {
            return 0;
        }
        int step = 0, curMax = 0, nextMax = 0;
        for (int i = 0; i < size; i++) {
            if (i + nums[i] >= size - 1) {
                return step + 1;
            }
            nextMax = max(nextMax, i + nums[i]);
            if (i == curMax) {
                step++;
                curMax = nextMax;
            }
        }
        return 0;
    }
};

int main() {
    return 0;
}
