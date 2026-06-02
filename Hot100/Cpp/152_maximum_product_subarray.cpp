#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        int maxProd = nums[0];
        for (int i = 0; i < n; i++) {
            int tmpProd = 1;
            for (int j = i; j < n; j++) {
                tmpProd *= nums[j];
                maxProd = max(maxProd, tmpProd);
            }
        }
        return maxProd;
    }
};

class Solution2 {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        int maxPre = nums[0], minPre = nums[0], res = nums[0];
        for (int i = 1; i < n; i++) {
            int maxCur = max(nums[i], max(maxPre * nums[i], minPre * nums[i]));
            int minCur = min(nums[i], min(maxPre * nums[i], minPre * nums[i]));
            res = max(res, maxCur);
            maxPre = maxCur;
            minPre = minCur;
        }
        return res;
    }
};

int main() {
    vector v{1, 0, -5, 2, 3, -8, -9};
    cout << Solution().maxProduct(v) << endl;
    return 0;
}
