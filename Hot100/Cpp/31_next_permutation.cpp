#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        // 要使 1246321 变成最小的、大于自身的数，首先从后面找到一个（从前往后的）升序关系，因为降序排列已经是所有序列中最大的值。
        // 然后再从后部找到一个比升序关系中较小值大的数，交换他们，前面部分就做好了调整。
        // 最后将剩余部分按升序排列取得最小值。
        int n = nums.size(), p = n - 1, q = n - 1;
        while (p > 0 && nums[p - 1] >= nums[p]) p--;
        while (p > 0 && q > 0 && nums[q] <= nums[p - 1]) q--;
        if (p > 0) swap(nums[p - 1], nums[q]);
        sort(nums.begin() + p, nums.end());
    }
};

int main() {
    vector v{1, 2, 3};
    Solution().nextPermutation(v);
    return 0;
}
