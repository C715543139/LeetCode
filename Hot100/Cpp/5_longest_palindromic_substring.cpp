#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res{s[0]};
        vector v(s.size(), 1);
        for (int i = 1; i < s.length(); i++) {
            int check = i - 1 - v[i - 1];
            if (check >= 0 && s[check] == s[i]) { // 是否能构成大的回文串
                v[i] = i - check + 1;
                if (v[i] > res.length()) {
                    res = s.substr(check, i - check + 1);
                }
                continue;
            }

            check++; // 前一个字符对应回文串的开头，在其内部查找新的回文串
            for (int j = check; j < i; j++) {
                if (s[j] == s[i] && isPalindrome(s, j, i)) {
                    v[i] = i - j + 1;
                    if (v[i] > res.length()) {
                        res = s.substr(j, i - j + 1);
                    }
                    break;
                }
            }
        }
        return res;
    }

    static bool isPalindrome(const string &str, int start, int end) {
        for (; start < end; start++, end--) {
            if (str[start] != str[end]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s{"cbbd"};
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}
