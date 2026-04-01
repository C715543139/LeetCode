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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int len = 0;
        ListNode *cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }
        if (len == n) {
            return head->next;
        }

        cur = head;
        for (int i = 0; i < len - n - 1; i++, cur = cur->next) {}
        cur->next = cur->next->next;
        return head;
    }
};

class Solution2 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *v[31];
        auto temp = head;
        int size = 0;
        while (temp) {
            v[size++] = temp;
            temp = temp->next;
        }
        if (size == 1) {
            return nullptr;
        }
        if (size == n) {
            return head->next;
        }

        temp = v[size - n - 1];
        temp->next = temp->next->next;
        return head;
    }
};

int main() {
    return 0;
}
