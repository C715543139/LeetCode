#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // 0向右, 1向下, 2向左, 3向上
        vector<int> result;
        int m = matrix.size(), n = matrix[0].size();
        int direction = 0, i = 0, j = 0;
        for (int count = 0; count < m * n; count++) {
            result.push_back(matrix[i][j]);
            matrix[i][j] = 101;

            if (count == m * n - 1) {
                break;
            }

            if (direction == 0) {
                j++;
            }
            if (direction == 1) {
                i++;
            }
            if (direction == 2) {
                j--;
            }
            if (direction == 3) {
                i--;
            }

            if (j >= n) {
                j--;
                i++;
                direction = 1;
            }
            if (i >= m) {
                i--;
                j--;
                direction = 2;
            }
            if (j < 0) {
                i--;
                j++;
                direction = 3;
            }

            if (matrix[i][j] == 101) {
                if (direction == 3) {
                    i++;
                    j++;
                    direction = 0;
                } else if (direction == 0) {
                    i++;
                    j--;
                    direction = 1;
                } else if (direction == 1) {
                    i--;
                    j--;
                    direction = 2;
                } else if (direction == 2) {
                    i--;
                    j++;
                    direction = 3;
                }
            }
        }
        return result;
    }
};

int main() {
    auto matric = vector{
        vector{1, 2, 3, 4},
        vector{5, 6, 7, 8},
        vector{9, 10, 11, 12},
    };
    for (auto i: Solution().spiralOrder(matric)) {
        cout << i << " ";
    }
    return 0;
}
