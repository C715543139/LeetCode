#include <iostream>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> st;
        for (ListNode *a = headA; a != nullptr; a = a->next) {
            st.insert(a);
        }
        for (ListNode *b = headB; b != nullptr; b = b->next) {
            if (st.find(b) != st.end()) {
                return b;
            }
        }
        return nullptr;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for (ListNode *a = headA; a != nullptr; a = a->next) {
            a->val = -a->val;
        }
        for (ListNode *b = headB; b != nullptr; b = b->next) {
            if (b->val < 0) {
                for (ListNode *a = headA; a != nullptr; a = a->next) {
                    a->val = -a->val;
                }
                return b;
            }
        }
        for (ListNode *a = headA; a != nullptr; a = a->next) {
            a->val = -a->val;
        }
        return nullptr;
    }
};

class Solution3 {
    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        for (ListNode *a = headA; a != nullptr; a = a->next, lenA++) {}
        for (ListNode *b = headB; b != nullptr; b = b->next, lenB++) {}
        ListNode *pa = headA, *pb = headB;
        while (lenA > lenB) {
            pa = pa->next;
            lenA--;
        }
        while (lenB > lenA) {
            pb = pb->next;
            lenB--;
        }
        while (pa && pb) {
            if (pa == pb) {
                return pa;
            }
            pa = pa->next;
            pb = pb->next;
        }
        return nullptr;
    }
};

int main() {

    return 0;
}
