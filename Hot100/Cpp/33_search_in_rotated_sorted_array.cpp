#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        int p = 0;
        while (p < end && nums[p] < nums[p + 1]) p++;
        vector<int> newNums;
        if (p != end) {
            newNums.insert(newNums.begin(), nums.begin() + p + 1, nums.end());
            newNums.insert(newNums.end(), nums.begin(), nums.begin() + p + 1);
        } else {
            newNums = nums;
        }
        while (start <= end) {
            int mid = (start + end) / 2;
            if (newNums[mid] == target) {
                return (mid + p + 1) % nums.size();
            }
            if (newNums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        return -1;
    }
};

class Solution2 { //下标转换
public:
    int search(vector<int> &nums, int target) {
        int p = 0;
        while (p < nums.size() - 1 && nums[p] < nums[p + 1]) p++;
        int start = (p + 1) % nums.size();
        int m = 0, n = nums.size() - 1;
        while (m <= n) {
            int mid = ((m + n) / 2 + start) % nums.size();
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) m = (mid - start + nums.size()) % nums.size() + 1;
            else n = (mid - start + nums.size()) % nums.size() - 1;
        }
        return -1;
    }
};

int main() {
    vector v = {3, 5, 1};
    cout << Solution2().search(v, 5) << endl;
    return 0;
}
