#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector v(m + 1, vector(n + 1, INT_MAX / 2));
        for (int i = 0; i <= n; i++) v[0][i] = i;
        for (int i = 0; i <= m; i++) v[i][0] = i;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    v[i][j] = v[i - 1][j - 1];
                } else {
                    v[i][j] = min(v[i - 1][j], min(v[i][j - 1], v[i - 1][j - 1])) + 1;
                }
            }
        }
        return v[m][n];
    }
};

class Solution2 {
public:
    int minDistance(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector v(2, vector<int>(n + 1, INT_MAX / 2));

        for (int j = 0; j <= n; j++) {
            v[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            v[i % 2][0] = i; // 关键：每一行都要更新第 0 列

            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    v[i % 2][j] = v[(i - 1) % 2][j - 1];
                } else {
                    v[i % 2][j] = min(v[(i - 1) % 2][j], min(v[i % 2][j - 1], v[(i - 1) % 2][j - 1])) + 1;
                }
            }
        }

        return v[m % 2][n];
    }
};

int main() {
    string s1{"horse"}, s2{"ros"};
    cout << Solution().minDistance(s1, s2) << endl;
    return 0;
}
