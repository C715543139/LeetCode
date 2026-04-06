#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> v;
        int turn = 0, m = grid.size(), n = grid[0].size();
        while (true) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 2) {
                        if (i > 0 && grid[i - 1][j] == 1) {
                            v.emplace_back(i - 1, j);
                        }
                        if (i < m - 1 && grid[i + 1][j] == 1) {
                            v.emplace_back(i + 1, j);
                        }
                        if (j > 0 && grid[i][j - 1] == 1) {
                            v.emplace_back(i, j - 1);
                        }
                        if (j < n - 1 && grid[i][j + 1] == 1) {
                            v.emplace_back(i, j + 1);
                        }
                    }
                }
            }

            if (v.empty()) {
                break;
            }
            while (!v.empty()) {
                auto y = v.back().first, x = v.back().second;
                v.pop_back();
                grid[y][x] = 2;
            }
            turn++;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return turn;
    }
};

int main() {
    return 0;
}