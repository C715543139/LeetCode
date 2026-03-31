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
        ListNode *cur = nullptr, *next = head;
        while (next) {
            auto tmp = next->next;
            next->next = cur;
            cur = next;
            next = tmp;
        }
        return cur;
    }

    bool isPalindrome(ListNode* head) {
        if (!head->next) {
            return true;
        }

        int len = 1;
        ListNode* cur = head;
        for (; cur->next; cur = cur->next, ++len) {}

        cur = head;
        for (int i = 0; i < len / 2; i++, cur = cur->next) {}

        ListNode *tail = reverseList(cur);
        cur = head;
        for (int i = 0; i < len / 2; i++, cur = cur->next, tail = tail->next) {
            if (cur->val != tail->val) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}