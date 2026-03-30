#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > zeros;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zeros.push_back({i, j});
                }
            }
        }
        for (auto zero: zeros) {
            int row = zero[0];
            int col = zero[1];
            for (int i = 0; i < m; i++) {
                matrix[i][col] = 0;
            }
            for (int j = 0; j < n; j++) {
                matrix[row][j] = 0;
            }
        }
    }
};

class Solution2 {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool row_zero = false, col_zero = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                col_zero = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                row_zero = true;
            }
        }
        // 将0移动到第一行和第一列
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // 检查行和列是否为0
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 检查第一行和第一列是否为0
        if (row_zero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (col_zero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    auto matric = vector{
        vector{0, 1, 2, 0},
        vector{3, 4, 5, 2},
        vector{1, 3, 1, 5}
    };
    Solution2().setZeroes(matric);
    for (const auto &i: matric) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
