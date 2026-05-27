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

int main() {
    cout << Solution().numSquares(13) << endl;
    return 0;
}
