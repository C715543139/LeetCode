#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size() / 2;
        unordered_map<int, int> mp;
        for (int num: nums) {
            mp[num]++;
            if (mp[num] > n) {
                return num;
            }
        }
        return -1;
    }
};

class Solution2 { // 元素相消，多的剩下
public:
    int majorityElement(vector<int> &nums) {
        int cur = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                cur = nums[i];
                count = 1;
            } else if (cur == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        return cur;
    }
};

int main() {
    return 0;
}
