#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class MedianFinder {
    priority_queue<int> bh;
    priority_queue<int, vector<int>, greater<>> sh;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (!sh.empty() && num >= sh.top()) sh.push(num);
        else bh.push(num);
    }

    double findMedian() {
        adjust();
        if (bh.size() == sh.size()) {
            return (bh.top() + sh.top()) / 2.0;
        }
        return bh.top();
    }

    void adjust() {
        while (int(bh.size()) - int(sh.size()) > 1) {
            sh.push(bh.top());
            bh.pop();
        }

        while (int(sh.size()) - int(bh.size()) > 0) {
            bh.push(sh.top());
            sh.pop();
        }
    }
};

int main() {
    MedianFinder medianFinder = MedianFinder();
    medianFinder.addNum(40);   // arr = [1]
    medianFinder.addNum(12);   // arr = [1, 2]
    medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
    medianFinder.addNum(16);   // arr[1, 2, 3]
    medianFinder.addNum(35);   // arr[1, 2, 3]
    medianFinder.addNum(19);   // arr[1, 2, 3]
    medianFinder.addNum(34);   // arr[1, 2, 3]
    medianFinder.addNum(35);   // arr[1, 2, 3]
    medianFinder.findMedian(); // return 2.0
    return 0;
}
