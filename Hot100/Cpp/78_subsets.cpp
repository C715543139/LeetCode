#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int> &nums) {
        auto b = vector<int>();
        build(b, nums);
        return res;
    }

    void build(vector<int> &built, vector<int> &remain) {
        res.push_back(built);

        auto r = remain;
        for (int i = remain.size() - 1; i >= 0; i--) {
            built.push_back(remain[i]);
            r.pop_back();
            build(built, r);
            built.pop_back();
        }
    }
};

int main() {
    vector nums{0, 1, 2};
    Solution().subsets(nums);
    return 0;
}
