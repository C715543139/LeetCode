#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector v(amount + 1, 65535);
        v[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (const int coin : coins) {
                if (i >= coin) {
                    v[i] = min(v[i], v[i - coin] + 1);
                }
            }
        }
        return v[amount] == 65535 ? -1 : v[amount];
    }
};

int main() {
    vector v{2};
    cout << Solution().coinChange(v, 11) << endl;
    return 0;
}
