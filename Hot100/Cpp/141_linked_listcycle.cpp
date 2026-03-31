#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *f = head, *s = head;
        while (f && f->next) {
            f = f->next->next;
            s = s->next;
            if (f == s) {
                return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        while (head) {
            if (head->val == 100002) {
                return true;
            }
            head->val = 100002;
            head = head->next;
        }
        return false;
    }
};

int main() {
    return 0;
}
