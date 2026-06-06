#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector v(m, vector(n, 0));
        for (int i = 1; i < m; ++i) v[i][0] = v[i - 1][0] + grid[i - 1][0];
        for (int i = 1; i < n; ++i) v[0][i] = v[0][i - 1] + grid[0][i - 1];

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                v[i][j] = min(v[i - 1][j] + grid[i - 1][j], v[i][j - 1] + grid[i][j - 1]);
            }
        }
        return v[m - 1][n - 1] + grid[m - 1][n - 1];
    }
};

int main() {
    vector v{vector{1, 2}, vector{1, 1}};
    cout << Solution().minPathSum(v) << endl;
    return 0;
}
