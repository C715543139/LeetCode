#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // 将原数放在高位
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] += 1000;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] |= (matrix[n - j - 1][i] & 0xFFF) << 12;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = ((matrix[i][j] >> 12) & 0xFFF) - 1000;
            }
        }
    }
};

int main() {
    auto matrix = vector{
        vector{5, 1, 9, 11},
        vector{2, 4, 8, 10},
        vector{13, 3, 6, 7},
        vector{15, 14, 12, -16},
    };
    Solution().rotate(matrix);
    for (const auto& i : matrix) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
