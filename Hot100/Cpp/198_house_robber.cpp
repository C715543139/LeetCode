#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int res;

    int rob(vector<int> &nums) {
        f(nums, -2, 0, 0);
        return res;
    }

    void f(vector<int> &nums, int last, int cur, int sum) {
        if (cur == nums.size() - 1) {
            if (cur > last + 1) {
                res = max(res, sum + nums[cur]);
            } else {
                res = max(res, sum);
            }
            return;
        }

        if (cur > last + 1) {
            f(nums, cur, cur + 1, sum + nums[cur]);
        }
        f(nums, last, cur + 1, sum);
    }
};

class Solution2 {
public:
    int rob(vector<int> &nums) {
        int lastStolenMax = 0, lastPassMax = 0;
        for (const int num: nums) {
            int stolenMax = lastPassMax + num;
            int passMax = max(lastStolenMax, lastPassMax);
            lastStolenMax = stolenMax;
            lastPassMax = passMax;
        }
        return max(lastPassMax, lastStolenMax);
    }
};

int main() {
    vector nums{
        2, 1, 1, 2
    };
    cout << Solution2().rob(nums) << endl;
    return 0;
}
