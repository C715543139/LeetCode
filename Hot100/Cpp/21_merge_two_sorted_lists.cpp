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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *head, *cur = nullptr;
        if (list1 && list2) {
            if (list1->val < list2->val) {
                cur = head = list1;
                list1 = list1->next;
            } else {
                cur = head = list2;
                list2 = list2->next;
            }
        } else {
            head = list1 ? list1 : list2;
        }
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                cur = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                cur = list2;
                list2 = list2->next;
            }
        }
        while (list1 && cur) {
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }
        while (list2 && cur) {
            cur->next = list2;
            list2 = list2->next;
            cur = cur->next;
        }
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
    ListNode *l1 = new ListNode(3), *l2 = new ListNode(7);
    l1 = new ListNode(-9, l1);
    l2 = new ListNode(5, l2);
    l1 = Solution().mergeTwoLists(l1, l2);
    return 0;
}
