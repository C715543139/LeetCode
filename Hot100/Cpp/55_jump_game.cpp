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
        if (idx + nums[idx] >= last) {
            visited[last] = true;
            return;
        }
        for (int i = 1; i <= nums[idx] && i + idx <= last && !visited[last]; i++) {
            if (!visited[i + idx]) f(i + idx, last, nums);
        }
    }
};

class Solution2 {
public:
    bool canJump(vector<int> &nums) {
        int maxDist = 0;
        size_t size = nums.size();
        for (int i = 0; i < size; i++) {
            if (i <= maxDist) {
                maxDist = max(maxDist, i + nums[i]);
                if (maxDist >= size - 1) {
                    return true;
                }
            } else {
                return false;
            }
        }
        return false;
    }
};

int main() {
    vector v = {3, 0, 8, 2, 0, 0, 1};
    Solution2().canJump(v);
    return 0;
}
