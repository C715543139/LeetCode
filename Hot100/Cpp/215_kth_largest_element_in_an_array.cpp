#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue pq(nums.begin(), nums.end());
        while (k-- > 0) pq.pop();
        return pq.top();
    }
};

class Solution2 {
public:
    int findKthLargest(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

class Solution3 {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int l = 0, r = nums.size() - 1;
        k = nums.size() - k;
        while (true) {
            if (l >= r) return nums[k];
            int p = nums[l + (r - l) / 2], start = l, end = r;
            while (l <= r) {
                while (l <= r && nums[l] < p) l++;
                while (l <= r && nums[r] > p) r--;
                if (l <= r) {
                    swap(nums[l], nums[r]);
                    l++;
                    r--;
                }
            }
            if (r < k) {
                r = end;
            } else {
                l = start;
            }
        }
    }
};

class Solution4 {
public:
    int findKthLargest(vector<int> &nums, int k) {
        vector<int> big, small, equal, v = nums;
        while (true) {
            int p = v[rand() % v.size()];
            for (int num: v) {
                if (num < p) small.push_back(num);
                if (num > p) big.push_back(num);
                if (num == p) equal.push_back(num);
            }
            if (big.size() < k && big.size() + equal.size() >= k) return p;
            if (big.size() >= k) {
                v = big;
                big.clear();
            } else {
                small.insert(small.end(), equal.begin(), equal.end());
                v = small;
            }
            small.clear();
            equal.clear();
        }
    }
};

int main() {
    vector v = {-1, 2, 0};
    cout << Solution4().findKthLargest(v, 3);
    return 0;
}
