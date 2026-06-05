#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0, n = s.length();
        for (int i = 0; i < s.size(); i++) {
            int count = 0;
            for (int j = i; j < s.size() && count >= 0 && count <= n - j; j++) {
                if (s[j] == '(') {
                    count++;
                } else {
                    count--;
                    if (count == 0) {
                        maxLen = max(maxLen, j - i + 1);
                    }
                }
            }
        }
        return maxLen;
    }
};

class Solution2 {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        vector v(s.length(), 0);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')')  {
                if (i > 2) {
                    if (s[i - 1] == '(') {
                        v[i] = v[i - 2] + 2;
                    } else {
                        int l = v[i - 1];
                        if (i - l - 1 >= 0 && s[i - l - 1] == '(') {
                            v[i] = (i - l - 2 >= 0 ? v[i - l - 2] : 0) + l + 2;
                        }
                    }
                } else {
                    if (s[i - 1] == '(') {
                        v[i] = 2;
                    }
                }
            }
            maxLen = max(maxLen, v[i]);
        }
        return maxLen;
    }
};

int main() {
    string s{
        "((()))())"
    };
    cout << Solution2().longestValidParentheses(s) << endl;
    return 0;
}
