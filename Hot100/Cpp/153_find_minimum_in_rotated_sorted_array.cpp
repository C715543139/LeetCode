#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
        for (auto &num : nums) {
            res = min(res, num);
        }
        return res;
    }
};

int main() {
    return 0;
}