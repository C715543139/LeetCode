#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector v(n + 1, 10001);
        v[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                v[i] = min(v[i], v[i - j * j] + 1);
            }
        }
        return v[n];
    }
};

class Solution2 {
public:
    int numSquares(int n) {
        int r = floor(sqrt(n));
        vector v(n + 1, 10001);
        v[0] = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = i * i; j <= n; j++) {
                v[j] = min(v[j], v[j - i * i] + 1);
            }
        }
        return v[n];
    }
};

int main() {
    cout << Solution2().numSquares(12) << endl;
    return 0;
}
