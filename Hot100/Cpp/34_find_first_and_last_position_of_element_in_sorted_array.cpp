#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int p = 0, q = nums.size() - 1;
        while (p <= q) {
            int m = (p + q) / 2;
            if (nums[m] == target) {
                p = q = m;
                while (p > 0 && nums[p - 1] == target) p--;
                while (q < nums.size() - 1 && nums[q + 1] == target) q++;
                return {p, q};
            }
            if (nums[m] < target) p = m + 1;
            else q = m - 1;
        }
        return {-1, -1};
    }
};

int main() {
    return 0;
}
