#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<char>> b;
    string w;

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        b = board;
        w = word;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (find(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool find(int i, int j, int p) {
        if (p == w.length() - 1) {
            return w[p] == b[i][j];
        }

        if (w[p] == b[i][j]) {
            b[i][j] = '.';
            bool flag = false;
            if (i > 0) flag |= find(i - 1, j, p + 1);
            if (j > 0) flag |= find(i, j - 1, p + 1);
            if (i < m - 1) flag |= find(i + 1, j, p + 1);
            if (j < n - 1) flag |= find(i, j + 1, p + 1);
            b[i][j] = w[p];
            return flag;
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    cout << Solution().exist(board, "ABCB");
    return 0;
}