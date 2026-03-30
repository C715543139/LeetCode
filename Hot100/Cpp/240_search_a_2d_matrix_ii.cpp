#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int p = 0, q = 0;
        while (true) {
            if (matrix[p][q] == target) {
                return true;
            }
            if (matrix[p][q] > target) {
                if (matrix[p][0] > target && matrix[0][q] > target ) {
                    return false;
                }
                for (int row = 0; row < p; row++) {
                    if (matrix[row][q] == target) {
                        return true;
                    }
                }
                for (int col = 0; col < q; col++) {
                    if (matrix[p][col] == target) {
                        return true;
                    }
                }
            }
            if (p < m - 1 && q < n - 1) {
                p++;
                q++;
            } else if (p == m - 1 && q < n - 1) {
                q++;
            } else if (q == n - 1 && p < m - 1) {
                p++;
            } else {
                return false;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    cout << Solution().searchMatrix(matrix, 15) << endl;
    return 0;
}
