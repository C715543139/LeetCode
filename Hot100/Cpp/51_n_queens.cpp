#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> board;
    vector<bool> f1, f2, f3, f4;
    int N;

    vector<vector<string>> solveNQueens(int n) {
        board = vector(n, string(n, '.'));
        f1 = f2 = vector(n, false);
        f3 = f4 = vector(2 * n, false);
        N = n;
        build(0, n);
        return res;
    }

    void build(int i, int remain) {
        if (remain == 0) {
            res.push_back(board);
            return;
        }
        if (i == N) {
            return;
        }
        for (int k = 0; k < N; ++k) {
            if (check(i, k)) {
                board[i][k] = 'Q';
                f1[i] = true;
                f2[k] = true;
                f3[i - k + N] = true;
                f4[i + k] = true;
                build(i + 1, remain - 1);
                board[i][k] = '.';
                f1[i] = false;
                f2[k] = false;
                f3[i - k + N] = false;
                f4[i + k] = false;
            }
        }
    }

    bool check(int i, int j) {
        return !(f1[i] || f2[j] || f3[i - j + N] || f4[i + j]);
    }
};

int main() {
    Solution().solveNQueens(12);
    return 0;
}
