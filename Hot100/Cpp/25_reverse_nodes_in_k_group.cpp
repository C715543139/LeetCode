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
    ListNode *reverse(ListNode *head, int k) {
        if (k == 1) return head;
        ListNode *cur = head, *next = head->next;
        for (int i = 0; i < k - 1; i++) {
            ListNode *temp = next->next;
            next->next = cur;
            cur = next;
            next = temp;
        }
        head->next = next;
        return cur;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 1) return head;

        int len = 0;
        for (ListNode *cur = head; cur != nullptr; len++, cur = cur->next) {}

        if ((len -= k) < 0) {
            return head;
        }

        ListNode *nextStart = head, *start = head, *lastTail;
        for (int i = 0; i < k; i++, nextStart = nextStart->next) {}
        head = reverse(start, k);
        lastTail = start;
        start = nextStart;

        while ((len -= k) >= 0) {
            for (int i = 0; i < k; i++, nextStart = nextStart->next) {}
            lastTail->next = reverse(start, k);
            lastTail = start;
            start = nextStart;
        }
        return head;
    }
};

int main() {
    ListNode *head = nullptr;
    for (int i = 1; i <= 8; i++) {
        head = new ListNode(i, head);
    }
    head = Solution().reverseKGroup(head, 3);
    return 0;
}
