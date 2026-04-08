#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) {
        vector<string> built;
        build(built, s, 0);
        return res;
    }

    void build(vector<string> &built, const string &remain, int index) {
        if (index == remain.size() - 1) {
            if (check(remain)) {
                built.push_back(remain);
                res.push_back(built);
                built.pop_back();
            }
            return;
        }
        if (check(remain.substr(0, index + 1))) {
            build(built, remain, index + 1);

            built.push_back(remain.substr(0, index + 1));
            build(built, remain.substr(index + 1), 0);
            built.pop_back();
        } else {
            build(built, remain, index + 1);
        }
    }

    static bool check(const string &s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    auto s = string{"aabcddfffwdadasssa"};
    Solution().partition(s);
    return 0;
}