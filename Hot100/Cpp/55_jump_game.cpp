#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> visited;

    bool canJump(vector<int> &nums) {
        visited = vector(nums.size(), false);
        f(0, nums.size() - 1, nums);
        return visited[nums.size() - 1];
    }

    void f(const int idx, const int last, vector<int> &nums) {
        visited[idx] = true;
        for (int i = 1; i <= nums[idx] && i + idx <= last && !visited[last]; i++) {
            if (!visited[i + idx]) f(i + idx, last, nums);
        }
    }
};

int main() {
    vector v = {3,0,8,2,0,0,1};
    Solution().canJump(v);
    return 0;
}
