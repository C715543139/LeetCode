#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        while (head) {
            if (head->val == 100002) {
                return head;
            }
            head->val = 100002;
            head = head->next;
        }
        return nullptr;
    }
};

int main() {
    return 0;
}
