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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        if (lists.size() == 1) {
            return lists[0];
        }

        ListNode *head = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
};

class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 最小堆
        struct cmp {
            bool operator() (ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };

        if (lists.empty()) {
            return nullptr;
        }

        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        for (const auto node : lists) {
            for (ListNode *cur = node; cur; cur = cur->next) {
                q.push(cur);
            }
        }

        ListNode hair;
        for (ListNode *cur = &hair; !q.empty(); q.pop()) {
            cur->next = q.top();
            cur = cur->next;
            cur->next = nullptr;
        }
        return hair.next;
    }
};

int main() {
    ListNode *head = new ListNode(-1);
    head = new ListNode(-1, head);
    head = new ListNode(-1, head);
    auto list = vector{head};
    head = new ListNode(-1);
    head = new ListNode(-2, head);
    head = new ListNode(-2, head);
    list.push_back(head);
    head = Solution2().mergeKLists(list);
    return 0;
}