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

class Solution2 {
public:
    vector<vector<string>> res;
    vector<vector<int>> flag;
    string S;
    int len;

    vector<vector<string>> partition(string s) {
        S = s;
        len = s.size();
        flag = vector(len, vector(len, 2));
        vector<string> built;
        build(built, 0, 0);
        return res;
    }

    void build(vector<string> &built, int start, int index) {
        if (start + index == len - 1) {
            if (check(start, start + index)) {
                built.push_back(S.substr(start, index + 1));
                res.push_back(built);
                built.pop_back();
            }
            return;
        }
        if (check(start, start + index)) {
            build(built, start, index + 1);

            built.push_back(S.substr(start, index + 1));
            build(built, start + index + 1, 0);
            built.pop_back();
        } else {
            build(built, start, index + 1);
        }
    }

    bool check(int i, int j) {
        if (flag[i][j] != 2) {
            return flag[i][j];
        }
        for (int k = 0; i + k < j - k; k++) {
            if (S[i + k] != S[j - k]) {
                flag[i][j] = 0;
                return false;
            }
        }
        flag[i][j] = 1;
        return true;
    }
};

int main() {
    auto s = string{"aab"};
    Solution2().partition(s);
    return 0;
}
