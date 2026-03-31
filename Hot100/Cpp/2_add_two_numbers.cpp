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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0), *cur = head;
        int carry = 0;
        while (l1 && l2) {
            cur->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
            if (l1 || l2) {
                cur->next = new ListNode(0);
                cur = cur->next;
            }
        }
        while (l1) {
            cur->val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
            if (l1) {
                cur->next = new ListNode(0);
                cur = cur->next;
            }
        }
        while (l2) {
            cur->val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
            if (l2) {
                cur->next = new ListNode(0);
                cur = cur->next;
            }
        }
        if (carry > 0) {
            cur->next = new ListNode(carry);
        }
        return head;
    }
};

int main() {
    ListNode *l1 = new ListNode(9);
    ListNode *l2 = new ListNode(9);
    l1 = new ListNode(5, l1);
    l2 = new ListNode(5, l2);
    l2 = new ListNode(5, l2);
    l1 = Solution().addTwoNumbers(l1, l2);
    return 0;
}
