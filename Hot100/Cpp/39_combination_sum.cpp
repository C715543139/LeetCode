#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res, accum{{0}};
        while (res.size() < 150 && !accum.empty()) {
            vector<vector<int>> temp;
            for (const auto &num: candidates) {
                for (const auto &v: accum) {
                    temp.push_back(v);
                    auto &back = temp.back();
                    back.push_back(num);
                    back[0] += num;
                    if (back[0] == target) {
                        back.erase(back.begin());
                        res.push_back(back);
                        temp.pop_back();
                    } else if (back[0] > target) {
                        temp.pop_back();
                    }
                }
            }
            accum = std::move(temp);
            if (res.size() >= 150) {
                uniq(res);
            }
        }
        uniq(res);
        return res;
    }

    void uniq(vector<vector<int>> &vv) {
        for (auto &v: vv) sort(v.begin(), v.end());
        sort(vv.begin(), vv.end());
        vv.erase(unique(vv.begin(), vv.end()), vv.end());
    }
};

class Solution2 {
public:
    vector<vector<int>> res;
    vector<int> c;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        c = candidates;
        vector<int> picked;
        search(picked, target, 0);
        return res;
    }

    void search(vector<int> &picked, int target, int index) {
        if (index == c.size()) {
            return;
        }
        if (target == 0) {
            res.push_back(picked);
            return;
        }
        search(picked, target, index + 1);

        if (target - c[index] >= 0) {
            picked.push_back(c[index]);
            search(picked, target - c[index], index);
            picked.pop_back();
        }
    }
};

int main() {
    auto candidates = vector{2, 3, 6, 7};
    auto target = 7;
    Solution2().combinationSum(candidates, target);
    return 0;
}
