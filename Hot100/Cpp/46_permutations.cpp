#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        auto b = vector<int>();
        build(b, nums);
        return res;
    }

    void build(vector<int> &built, vector<int> &remain) {
        if (remain.empty()) {
            res.push_back(built);
            return;
        }

        for (int i = 0; i < remain.size(); i++) {
            int temp = remain[i];
            built.push_back(remain[i]);
            remain.erase(remain.begin() + i);
            build(built, remain);
            remain.insert(remain.begin() + i, temp);
            built.pop_back();
        }
    }
};

int main() {
    return 0;
}
