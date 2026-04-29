#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class MinStack {
public:
    priority_queue<int, vector<int>, greater<>> minHeap;
    stack<int> s;
    unordered_map<int, int> removed;

    MinStack() {}

    void push(int val) {
        s.push(val);
        minHeap.push(val);
    }

    void pop() {
        removed[s.top()]++;
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        while (removed.count(minHeap.top()) && removed[minHeap.top()] > 0) {
            removed[minHeap.top()]--;
            minHeap.pop();
        }
        return minHeap.top();
    }
};

class MinStack2 {
public:
    stack<int> s, minS;

    MinStack2() {
        minS.push(INT_MAX);
    }

    void push(int val) {
        s.push(val);
        minS.push(min(val, minS.top()));
    }

    void pop() {
        s.pop();
        minS.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};

int main() {
    return 0;
}
