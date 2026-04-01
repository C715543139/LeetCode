#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
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
    ListNode *sortList(ListNode *head) {
        vector<int> v;
        for (ListNode *cur = head; cur; cur = cur->next) {
            v.push_back(cur->val);
        }
        sort(v.begin(), v.end());

        ListNode *newHead = nullptr, *last = new ListNode();
        for (auto i: v) {
            last->next = new ListNode(i);
            last = last->next;
            if (!newHead) {
                newHead = last;
            }
        }
        return newHead;
    }
};

class Solution2 {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;

        int len = 0;
        for (ListNode *cur = head; cur; cur = cur->next, len++) {}

        ListNode *hair = new ListNode(0, head);
        for (int step = 1; step < len; step *= 2) {
            ListNode *currentGroup = hair->next, *lastGroup = hair;
            while (currentGroup) {
                ListNode *list1 = currentGroup;

                for (int i = 0; i < step - 1 && currentGroup->next; i++, currentGroup = currentGroup->next) {}
                ListNode *list2 = currentGroup->next;
                currentGroup->next = nullptr;

                currentGroup = list2;
                for (int i = 0; i < step - 1 && currentGroup && currentGroup->next;
                     i++, currentGroup = currentGroup->next) {}
                ListNode *nextGroup = nullptr;
                if (currentGroup) {
                    nextGroup = currentGroup->next;
                    currentGroup->next = nullptr;
                }

                lastGroup->next = merge(list1, list2);
                while (lastGroup->next) { lastGroup = lastGroup->next; }
                currentGroup = nextGroup;
            }
        }
        return hair->next;
    }

    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *hair = new ListNode(0);
        ListNode *temp = hair, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return hair->next;
    }
};

int main() {
    return 0;
}
