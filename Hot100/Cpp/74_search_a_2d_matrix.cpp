#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            if (target <= matrix[i][col - 1]) {
                for (int j = col - 1; j >= 0; j--) {
                    if (matrix[i][j] == target) {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}