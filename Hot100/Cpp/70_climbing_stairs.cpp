#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> v;

    Solution() : v(46, -1) {
        v[1] = 1;
        v[2] = 2;
    }

    int climbStairs(int n) {
        if (v[n] != -1) return v[n];
        v[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return v[n];
    }
};

int main() {
    cout << Solution().climbStairs(45) << endl;
    return 0;
}
