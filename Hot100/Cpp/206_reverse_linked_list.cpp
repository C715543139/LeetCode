#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return head;
        }

        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

class Solution2 {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *cur = nullptr, *next = head;
        while (next) {
            auto tmp = next->next;
            next->next = cur;
            cur = next;
            next = tmp;
        }
        return cur;
    }
};

int main() {
    ListNode *p = nullptr;
    for (int i = 1; i < 6; i++) {
        p = new ListNode(i, p);
    }
    p = Solution2().reverseList(p);
    return 0;
}
