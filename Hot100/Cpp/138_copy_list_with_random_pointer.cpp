#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) { return nullptr; }

        unordered_map<Node *, Node *> ump;
        ump[head] = new Node(head->val);
        for (Node *cur = head; cur; cur = cur->next) {
            if (cur->next) {
                ump[cur->next] = new Node(cur->next->val);
            } else {
                ump[cur->next] = nullptr;
            }
            ump[cur]->next = ump[cur->next];
        }
        for (Node *cur = head; cur; cur = cur->next) {
            ump[cur]->random = ump[cur->random];
        }
        return ump[head];
    }
};

int main() {
    Node *head = new Node(3);
    head->next = new Node(3);
    head->next->next = new Node(3);
    head->next->random = head;
    head = Solution().copyRandomList(head);
    return 0;
}
