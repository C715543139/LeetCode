#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, curMin = prices[0];
        for (int price: prices) {
            res = max(res, price - curMin);
            curMin = min(curMin, price);
        }
        return res;
    }
};

int main() {
    return 0;
}