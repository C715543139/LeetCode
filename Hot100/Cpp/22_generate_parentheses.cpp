#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        string built{"("};
        build(built, n - 1, n);
        return res;
    }

    void build(string &built, int l, int r) {
        if (l == 0 && r == 0) {
            res.push_back(built);
            return;
        }
        if (l == 0) {
            built.push_back(')');
            build(built, l, r - 1);
            built.pop_back();
            return;
        }

        built.push_back('(');
        build(built, l - 1, r);
        built.pop_back();

        if (l < r) {
            built.push_back(')');
            build(built, l, r - 1);
            built.pop_back();
        }
    }
};

class Solution2 {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        build("(", n - 1, n);
        return res;
    }

    void build(const string &built, int l, int r) {
        if (l == 0 && r == 0) {
            res.push_back(built);
            return;
        }
        if (l == 0) {
            build(built + ')', l, r - 1);
            return;
        }
        if (l < r) {
            build(built + '(', l - 1, r);
            build(built + ')', l, r - 1);
        } else if (l == r) {
            build(built + '(', l - 1, r);
        }
    }
};

int main() {
    Solution().generateParenthesis(3);
    return 0;
}
