#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector res = nums;
        for (int i = 1; i < res.size() - 1; ++i) {
            res[i] = res[i - 1] * res[i];
        }
        int rightProduct = 1;
        for (int i = res.size() - 1; i > 0; --i) {
            res[i] = res[i - 1] * rightProduct;
            rightProduct *= nums[i];
        }
        res[0] = rightProduct;
        return res;
    }
};

int main() {
    auto nums = vector{-1, -1};
    for (auto i: Solution().productExceptSelf(nums)) {
        cout << i << " ";
    }
    return 0;
}
