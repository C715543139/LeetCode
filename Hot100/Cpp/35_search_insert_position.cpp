#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        return find(target, nums, 0, nums.size() - 1);
    }

    int find(int target, vector<int> &nums, int start, int end) {
        if (start >= end) {
            return start + (nums[start] < target);
        }
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            return find(target, nums, mid + 1, end);
        }
        return find(target, nums, start, mid - 1);
    }
};

class Solution2 {
public:
    int searchInsert(vector<int> &nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start + (nums[start] < target);
    }
};

int main() {
    vector v = {1, 2};
    cout << Solution().searchInsert(v, 0) << endl;
    return 0;
}
