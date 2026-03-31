#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *prev = head;
        if (prev && prev->next) {
            ListNode *node1 = prev, *node2 = prev->next;
            node1->next = node2->next;
            node2->next = node1;
            head = node2;
            prev = node1;
        }
        while (prev && prev->next && prev->next->next) {
            ListNode *node1 = prev->next, *node2 = prev->next->next;
            node1->next = node2->next;
            node2->next = node1;
            prev->next = node2;
            prev = node1;
        }
        return head;
    }
};

int main() {
    return 0;
}
