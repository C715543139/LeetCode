#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i] & 0x1FFFF;
            int count = nums[num] & 1 << 17;
            if (count) {
                return num;
            }
            nums[num] |= 1 << 17;
        }
        return 0;
    }
};

int main() {
    vector v{1, 2, 3, 4, 5, 1};
    cout << Solution().findDuplicate(v) << endl;
    return 0;
}
