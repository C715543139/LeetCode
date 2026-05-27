#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static bool wordBreak(const string& s, vector<string> &wordDict) {
        vector v(s.size() + 1, false);
        v[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (const auto &j: wordDict) {
                if (i >= j.length()) {
                    v[i] = v[i] || (v[i - j.length()] && compare(s, i - j.length(), j));
                }
            }
        }
        return v[s.size()];
    }

    static bool compare(const string &s, int idx, const string &word) {
        for (const char c: word) {
            if (c != s[idx++]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s{"applepenapple"};
    vector v{string{"apple"}, string{"pen"}};
    cout << Solution().wordBreak(s, v) << endl;
    return 0;
}
