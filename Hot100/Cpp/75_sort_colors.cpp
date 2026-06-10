#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int p = 0, q = 0, n = nums.size();
        while (p < n && nums[p] == 0) p++;
        q = p;

        while (p < n && q < n) {
            while (p < n && nums[p] != 0) p++;
            if (p < n) {
                while (q < n && nums[q] == 0) q++;
                if (q < n) {
                    swap(nums[p], nums[q]);
                    p++;
                    q++;
                }
            }
        }

        p = 0;
        while (p < n && (nums[p] == 0 || nums[p] == 1)) p++;
        q = p;

        while (p < n && q < n) {
            while (p < n && nums[p] != 1) p++;
            if (p < n) {
                while (q < n && nums[q] == 1) q++;
                if (q < n) {
                    swap(nums[p], nums[q]);
                    p++;
                    q++;
                }
            }
        }
    }
};

int main() {
    vector v{0,0,0,0,2, 0, 2, 1, 1, 0, 1, 1};
    Solution().sortColors(v);
    return 0;
}
