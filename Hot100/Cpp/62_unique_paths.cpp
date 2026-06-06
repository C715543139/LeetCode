#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector v(2, vector(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                v[i % 2][j] = v[(i - 1) % 2][j] + v[i % 2][j - 1];
            }
        }
        return v[(m - 1) % 2][n - 1];
    }
};

int main() {
    cout << Solution().uniquePaths(3, 7) << endl;
    return 0;
}
